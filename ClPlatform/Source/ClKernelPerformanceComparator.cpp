#include "ClKernelPerformanceComparator.hpp"
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

void ClKernelPerformanceComparator::addKernel( boost::shared_ptr<IClKernel> newKernel)
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
         optional<boost::shared_ptr<IClKernel> > kernel = newParametrizedKernel->getKernel(param);
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

        set<boost::shared_ptr<IClKernel> >::iterator testedKernel = remainingKernels.begin();

        uint beginTime = clock.getUsec();
        //(*testedKernel)(l_randomData);

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

    ERROR << "Data generator not yet provided";

    return !remainingKernels.empty();
}

optional<boost::shared_ptr<IClKernel> > ClKernelPerformanceComparator::getBestKernel()
{
    return bestKernel;
}

