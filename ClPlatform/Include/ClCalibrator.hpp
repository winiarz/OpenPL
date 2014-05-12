#ifndef __CL_CALIBRATOR__
#define __CL_CALIBRATOR__

#include "stl.hpp"
#include "IClCalibrator.hpp"

class ClCalibrator : public IClCalibrator {
public:
    ClCalibrator();
    virtual void addPerformanceComparator(boost::shared_ptr<IClKernelPerformanceComparator>);
    virtual bool isCalibrationFinished();
    virtual bool calibrate();
private:
    set<boost::shared_ptr<IClKernelPerformanceComparator> > comparatorsSet;
};

#endif

