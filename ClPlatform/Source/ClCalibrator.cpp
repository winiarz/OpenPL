#include "ClCalibrator.hpp"
#include "IClKernelPerformanceComparator.hpp"

ClCalibrator::ClCalibrator() :
        comparatorsSet()
{

}

void ClCalibrator::setCalibrationEnabled(bool)
{

}

void ClCalibrator::addPerformanceComparator(boost::shared_ptr<IClKernelPerformanceComparator> newComparator)
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

    set<boost::shared_ptr<IClKernelPerformanceComparator> >::iterator comparator = comparatorsSet.begin();

    if ( !(*comparator)->comparationStep() ) 
    {
        comparatorsSet.erase(comparator);
    }

    return isCalibrationFinished();
}

