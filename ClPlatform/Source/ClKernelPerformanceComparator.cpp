#include "ClKernelPerformanceComparator.hpp"
#include "ClKernelSaver.hpp"
#include "ClError.hpp"
#include "logs.hpp"

ClKernelPerformanceComparator::ClKernelPerformanceComparator(IClock& p_clock) :
    clock(p_clock),
    bestKernel(none)
{
    dataGenerator = none;
    bestTime = std::numeric_limits<int>::max();
}

void ClKernelPerformanceComparator::setDataGenerator( boost::shared_ptr<IClDataGenerator> p_dataGenerator)
{
    dataGenerator = p_dataGenerator;
}

void ClKernelPerformanceComparator::addKernel( boost::shared_ptr<IClSingleImplementationKernel> newKernel)
{
    remainingKernels.insert(newKernel);
    if ( !bestKernel ) 
    {
        bestKernel = newKernel;
    }
}

void ClKernelPerformanceComparator::addParameterizedKernel( boost::shared_ptr<IClParameterizedKernel> newParametrizedKernel)
{
    boost::shared_ptr<set<int> > parameters = newParametrizedKernel->getNotRejectedParameters();
    BOOST_FOREACH( int param, *parameters)
    {
         optional<boost::shared_ptr<IClSingleImplementationKernel> > kernel = newParametrizedKernel->getKernel(param);
         if ( kernel ) 
         {
             addKernel(*kernel);
         }
    }
}

bool ClKernelPerformanceComparator::comparationStep()
{
    if ( dataGenerator && !remainingKernels.empty() ) 
    {
        vector<boost::shared_ptr<ClMemory> > l_randomData = (*dataGenerator)->getData();

        set<boost::shared_ptr<IClSingleImplementationKernel> >::iterator testedKernel = remainingKernels.begin();

        uint beginTime = clock.getUsec();
        //(*testedKernel)(l_randomData); TODO - run kernel here

        uint finishTime = clock.getUsec();
        uint workTime = finishTime - beginTime;
        if ( workTime < bestTime ) 
        {
            DEBUG << "better kernel found old bestTime = " << bestTime << " new bestTime = " << workTime;
            bestTime = workTime;
            bestKernel = *testedKernel;
            
        }

        remainingKernels.erase(testedKernel);
    }

    if ( !dataGenerator ) 
    {
        ERROR << "Data generator not yet provided";
    }

    return !remainingKernels.empty();
}

optional<boost::shared_ptr<IClSingleImplementationKernel> > ClKernelPerformanceComparator::getBestKernel()
{
    return bestKernel;
}

void ClKernelPerformanceComparator::saveToFile( FILE* file )
{
    if ( !dataGenerator ) 
    {
        ERROR << "Data generator not yet provided";
        throw FILE_WRITE_ERROR;
    }

    (*dataGenerator)->saveToFile( file );

    uint kernelsCount = remainingKernels.size();
    size_t writtenElems = fwrite( &kernelsCount, sizeof(kernelsCount), 1, file );
    if ( writtenElems < 1 ) 
    {
        throw FILE_WRITE_ERROR;
    }

    ClKernelSaver kernelSaver;

    for ( set<boost::shared_ptr<IClSingleImplementationKernel> >::iterator i = remainingKernels.begin(); i != remainingKernels.end(); ++i ) 
    {
        kernelSaver.saveKernel( (*i), file );
    }
}
