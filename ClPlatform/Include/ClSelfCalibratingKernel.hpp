#pragma once

#include "boost.hpp"
#include "IClKernel.hpp"

namespace OPL
{
class IClKernelPerformanceComparator;

class ClSelfCalibratingKernel : public IClKernel
{
public:
    ClSelfCalibratingKernel(shared_ptr<IClKernelPerformanceComparator> p_performanceComparator);

    virtual bool isSetUpSuccessfully();
    virtual bool operator!();
    virtual IClKernel& operator[](uint n);
    virtual IClKernel& operator()(uint, ... );
    virtual IClKernel& operator()(std::vector<IClMemory*>);
    virtual IClKernel& operator()(std::vector<shared_ptr<IClMemory>>);
      
    virtual ~ClSelfCalibratingKernel();
    bool calibrate(uint timeLimit);

    void saveToFile( std::string filename );
private:
    shared_ptr<IClKernelPerformanceComparator> performanceComparator;
};

}

