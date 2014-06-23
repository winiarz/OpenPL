#pragma once

#include "stl.hpp"
#include "IClCalibrator.hpp"

class ClCalibrator : public IClCalibrator {
public:
    ClCalibrator();
    virtual void addPerformanceComparator(std::shared_ptr<IClKernelPerformanceComparator>);
    virtual bool isCalibrationFinished();
    virtual bool calibrate();
private:
    set<std::shared_ptr<IClKernelPerformanceComparator> > comparatorsSet;
};

