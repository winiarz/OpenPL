#pragma once

#include "boost.hpp"
#include "IClKernel.hpp"
#include "IClKernelPerformanceComparator.hpp"

class ClSelfCalibratingKernel : public IClKernel
{
public:
    ClSelfCalibratingKernel(shared_ptr<OPL::IClKernelPerformanceComparator> p_performanceComparator);

    virtual bool isSetUpSuccessfully();
    virtual bool operator!();
    virtual IClKernel& operator[](uint n);
    virtual IClKernel& operator()(uint, ... );
    virtual IClKernel& operator()(std::vector<OPL::IClMemory*>);
    virtual IClKernel& operator()(std::vector<shared_ptr<OPL::IClMemory>>);
      
    virtual ~ClSelfCalibratingKernel();
    bool calibrate(uint timeLimit);

    void saveToFile( std::string filename );
private:
    shared_ptr<OPL::IClKernelPerformanceComparator> performanceComparator;
};

