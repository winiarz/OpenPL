#pragma once

#include "boost.hpp"

class IClKernelPerformanceComparator;

class IClCalibrator {
public:
    virtual void addPerformanceComparator(std::shared_ptr<IClKernelPerformanceComparator>) = 0;
    virtual bool isCalibrationFinished() = 0;
    virtual bool calibrate() = 0;
};

