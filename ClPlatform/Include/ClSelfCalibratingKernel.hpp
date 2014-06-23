#pragma once

#include "boost.hpp"
#include "IClKernel.hpp"
#include "IClKernelPerformanceComparator.hpp"

class ClSelfCalibratingKernel : public IClKernel
{
public:
    ClSelfCalibratingKernel(std::shared_ptr<IClKernelPerformanceComparator> p_performanceComparator);

    virtual bool isSetUpSuccessfully();
    virtual bool operator!();
    virtual IClKernel& operator[](uint n);
    virtual IClKernel& operator()(uint, ... );
    virtual IClKernel& operator()(std::vector<ClMemory*>);
    virtual IClKernel& operator()(std::vector<std::shared_ptr<ClMemory>>);
      
    virtual ~ClSelfCalibratingKernel();
    bool calibrate(uint timeLimit);

    void saveToFile( std::string filename );
private:
    std::shared_ptr<IClKernelPerformanceComparator> performanceComparator;
};

