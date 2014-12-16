#include "ClCalibrator.hpp"
#include "IClKernelPerformanceComparator.hpp"

namespace OPL
{

ClCalibrator::ClCalibrator() :
        comparatorsSet()
{

}

void ClCalibrator::addPerformanceComparator(shared_ptr<IClKernelPerformanceComparator> newComparator)
{
    comparatorsSet.insert(newComparator);
}

bool ClCalibrator::isCalibrationFinished()
{
    return comparatorsSet.empty();
}

bool ClCalibrator::calibrate()
{
    if (isCalibrationFinished() ) 
    {
        return true;
    }

    auto comparator = comparatorsSet.begin();

    if ( !(*comparator)->comparationStep() ) 
    {
        comparatorsSet.erase(comparator);
    }

    return isCalibrationFinished();
}

}

