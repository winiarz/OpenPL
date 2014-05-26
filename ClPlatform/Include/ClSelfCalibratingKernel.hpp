#ifndef __CL_SELF_CALIBRATING_KERNEL__
#define __CL_SELF_CALIBRATING_KERNEL__

#include "boost.hpp"
#include "IClKernel.hpp"
#include "IClKernelPerformanceComparator.hpp"

class ClSelfCalibratingKernel : public IClKernel
{
public:
    ClSelfCalibratingKernel(boost::shared_ptr<IClKernelPerformanceComparator> p_performanceComparator);

    virtual bool isSetUpSuccessfully();
    virtual bool operator!();
    virtual IClKernel& operator[](uint n);
    virtual IClKernel& operator()(uint, ... );
    virtual IClKernel& operator()(std::vector<ClMemory*>);
      
    virtual ~ClSelfCalibratingKernel();
    bool calibrate(uint timeLimit);

    void saveToFile( std::string filename );
private:
    boost::shared_ptr<IClKernelPerformanceComparator> performanceComparator;
};

#endif

