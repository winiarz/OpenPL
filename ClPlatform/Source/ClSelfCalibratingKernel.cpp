#include "ClSelfCalibratingKernel.hpp"
#include "IClSingleImplementationKernel.hpp"
#include "ClError.hpp"
#include "Clock.hpp"
#include "logs.hpp"
#include <stdarg.h>

ClSelfCalibratingKernel::ClSelfCalibratingKernel(shared_ptr<IClKernelPerformanceComparator> p_performanceComparator) :
        performanceComparator(p_performanceComparator)
{
}

bool ClSelfCalibratingKernel::isSetUpSuccessfully()
{
    optional<shared_ptr<IClSingleImplementationKernel> > optKernel =  performanceComparator->getBestKernel();
    if ( ! optKernel ) 
        return false;
    return (*optKernel)->isSetUpSuccessfully();
}


bool ClSelfCalibratingKernel::operator!()
{
    return !isSetUpSuccessfully();
}

 
IClKernel& ClSelfCalibratingKernel::operator[](uint n)
{
    optional<shared_ptr<IClSingleImplementationKernel> > optKernel =  performanceComparator->getBestKernel();
    if ( !optKernel ) 
    {
        throw NO_KERNEL_IN_COMPARATOR;
    }

    (*optKernel)->operator[](n);
    return *(*optKernel).get();
}

IClKernel& ClSelfCalibratingKernel::operator()(uint argumentNb, ... )
{
    std::vector<IClMemory*> args(argumentNb);
    va_list li;
    va_start(li,argumentNb);
    for(uint i=0; i < argumentNb; i++)
    {
        args[i] = va_arg(li,IClMemory*);
    }
    va_end(li);
    return operator()(args);
}

IClKernel& ClSelfCalibratingKernel::operator()(std::vector<IClMemory*> args)
{
    optional<shared_ptr<IClSingleImplementationKernel> > optKernel =  performanceComparator->getBestKernel();
    if ( !optKernel ) 
    {
        throw NO_KERNEL_IN_COMPARATOR;
    }

    (*optKernel)->operator()(args);
    return *(*optKernel).get();
}

IClKernel& ClSelfCalibratingKernel::operator()(std::vector<shared_ptr<IClMemory>> args)
{
    optional<shared_ptr<IClSingleImplementationKernel> > optKernel =  performanceComparator->getBestKernel();
    if ( !optKernel ) 
    {
        throw NO_KERNEL_IN_COMPARATOR;
    }

    (*optKernel)->operator()(args);
    return *(*optKernel).get();
}

ClSelfCalibratingKernel::~ClSelfCalibratingKernel()
{
}

bool ClSelfCalibratingKernel::calibrate(uint timeLimit)
{
    Clock clock;
    uint startTime = clock.getUsec();
    uint currentTime = startTime;

    while ( currentTime < startTime + timeLimit ) 
    {
        if( !performanceComparator->comparationStep() )
            return false;
        currentTime = clock.getUsec();
    }

    return true;
}

void ClSelfCalibratingKernel::saveToFile( std::string filename )
{
    FILE* file = fopen( filename.c_str(), "wb" );
    if ( file == NULL ) 
    {
        ERROR << "can't open file " << filename << " to write";
        throw FILE_WRITE_ERROR;
    }

    char prefix = 'S';

    size_t writtenElems = fwrite( &prefix, sizeof(prefix), 1, file);
    if ( writtenElems < 1 ) 
    {
        throw FILE_WRITE_ERROR;
    }

    performanceComparator->saveToFile( file );

    fclose(file);
}

