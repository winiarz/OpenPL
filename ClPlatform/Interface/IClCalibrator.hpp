#pragma once

class IClKernelPerformanceComparator;

class IClCalibrator {
public:
    virtual void addPerformanceComparator(shared_ptr<IClKernelPerformanceComparator>) = 0;
    virtual bool isCalibrationFinished() = 0;
    virtual bool calibrate() = 0;
};

