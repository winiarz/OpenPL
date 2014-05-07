#ifndef __I_CL_KERNEL_PERFORMANCE_COMPARATOR__
#define __I_CL_KERNEL_PERFORMANCE_COMPARATOR__

#include "boost.hpp"

class IClDataGenerator;
class IClKernel;
class IClParameterizedKernel;

class IClKernelPerformanceComparator {
public:
    virtual bool comparationStep()=0;
    virtual void setDataGenerator( boost::shared_ptr<IClDataGenerator>)=0;
    virtual void addKernel( boost::shared_ptr<IClKernel> )=0;
    virtual void addParametrizedKernel( boost::shared_ptr<IClParameterizedKernel> )=0;
    virtual boost::shared_ptr<IClKernel> getBestKernel()=0;
};

#endif

