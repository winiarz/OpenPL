#ifndef __CL_KERNEL_PERFORMANCE_COMPARATOR__
#define __CL_KERNEL_PERFORMANCE_COMPARATOR__

#include "IClKernelPerformanceComparator.hpp"
#include "IClDataGenerator.hpp"
#include "IClParameterizedKernel.hpp"
#include "IClock.hpp"

class ClKernelPerformanceComparator : public IClKernelPerformanceComparator {
public:
    ClKernelPerformanceComparator(IClock&);
    virtual bool comparationStep();
    virtual void setDataGenerator( boost::shared_ptr<IClDataGenerator>);
    virtual void addKernel( boost::shared_ptr<IClKernel> );
    virtual void addParameterizedKernel( boost::shared_ptr<IClParameterizedKernel> );
    virtual optional<boost::shared_ptr<IClKernel> > getBestKernel();
private:
    IClock& clock;
    optional<boost::shared_ptr<IClDataGenerator> > dataGenerator;
    set<boost::shared_ptr<IClKernel> > remainingKernels;
    uint bestTime;
    optional<boost::shared_ptr<IClKernel> > bestKernel;
};

#endif

