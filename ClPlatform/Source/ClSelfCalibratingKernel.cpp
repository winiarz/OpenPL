#include "ClSelfCalibratingKernel.hpp"
#include "ClError.hpp"
#include "Clock.hpp"
#include <stdarg.h>

ClSelfCalibratingKernel::ClSelfCalibratingKernel(boost::shared_ptr<IClKernelPerformanceComparator> p_performanceComparator) :
        performanceComparator(p_performanceComparator)
{
}

bool ClSelfCalibratingKernel::isSetUpSuccessfully()
{
    optional<boost::shared_ptr<IClKernel> > optKernel =  performanceComparator->getBestKernel();
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
    optional<boost::shared_ptr<IClKernel> > optKernel =  performanceComparator->getBestKernel();
    if ( !optKernel ) 
    {
        throw NO_KERNEL_IN_COMPARATOR;
    }

    (*optKernel)->operator[](n);
    return *(*optKernel).get();
}

IClKernel& ClSelfCalibratingKernel::operator()(uint argumentNb, ... )
{
    std::vector<ClMemory*> args(argumentNb);
    va_list li;
    va_start(li,argumentNb);
    for(uint i=0; i < argumentNb; i++)
    {
        args[i] = va_arg(li,ClMemory*);
    }
    va_end(li);
    return operator()(args);
}

IClKernel& ClSelfCalibratingKernel::operator()(std::vector<ClMemory*> args)
{
    optional<boost::shared_ptr<IClKernel> > optKernel =  performanceComparator->getBestKernel();
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
    }

    return true;
}

