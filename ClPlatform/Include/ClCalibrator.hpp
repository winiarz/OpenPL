#pragma once

#include "stl.hpp"
#include "IClCalibrator.hpp"

class ClCalibrator : public IClCalibrator {
public:
    ClCalibrator();
    virtual void addPerformanceComparator(shared_ptr<IClKernelPerformanceComparator>);
    virtual bool isCalibrationFinished();
    virtual bool calibrate();
private:
    set<shared_ptr<IClKernelPerformanceComparator> > comparatorsSet;
};

