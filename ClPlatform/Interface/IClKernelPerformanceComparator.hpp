#ifndef __I_CL_KERNEL_PERFORMANCE_COMPARATOR__
#define __I_CL_KERNEL_PERFORMANCE_COMPARATOR__

#include "boost.hpp"
#include "IClSingleImplementationKernel.hpp"

class IClDataGenerator;
class IClParameterizedKernel;

class IClKernelPerformanceComparator {
public:
    virtual bool comparationStep()=0;
    virtual void setDataGenerator( boost::shared_ptr<IClDataGenerator>)=0;
    virtual void addKernel( boost::shared_ptr<IClSingleImplementationKernel> )=0;
    virtual void addParameterizedKernel( boost::shared_ptr<IClParameterizedKernel> )=0;
    virtual optional<boost::shared_ptr<IClSingleImplementationKernel> > getBestKernel()=0;
    virtual void saveToFile( FILE* file ) = 0;
};

#endif

