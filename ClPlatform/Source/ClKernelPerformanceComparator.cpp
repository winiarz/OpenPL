#include "ClKernelPerformanceComparator.hpp"

ClKernelPerformanceComparator::ClKernelPerformanceComparator(IClock& p_clock) :
    clock(p_clock)
{
    bestTime = std::numeric_limits<int>::max();
}

void ClKernelPerformanceComparator::setDataGenerator( boost::shared_ptr<IClDataGenerator> p_dataGenerator)
{
    dataGenerator = p_dataGenerator;
}

void ClKernelPerformanceComparator::addKernel( boost::shared_ptr<IClKernel> newKernel)
{
    remainingKernels.insert(newKernel);
}

void ClKernelPerformanceComparator::addParametrizedKernel( boost::shared_ptr<IClParameterizedKernel> newParametrizedKernel)
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
    vector<boost::shared_ptr<ClMemory> > l_randomData = dataGenerator->getData();

    set<boost::shared_ptr<IClKernel> >::iterator testedKernel = remainingKernels.begin();
    //boost::shared_ptr<IClKernel> testedKernel = remainingKernels.begin();

    uint beginTime = clock.getUsec();
    //(*testedKernel)(l_randomData);

    uint finishTime = clock.getUsec();
    uint workTime = finishTime - beginTime;
    if ( workTime < bestTime ) 
    {
        bestKernel = *testedKernel;
    }

    remainingKernels.erase(testedKernel);

    return !remainingKernels.empty();
}

boost::shared_ptr<IClKernel> ClKernelPerformanceComparator::getBestKernel()
{
    return bestKernel;
}

