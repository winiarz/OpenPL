#pragma once

#include <CL/cl.h>
#include <stl.hpp>

typedef unsigned int uint;

class IClKernelCallStats;
class IClMemory;

class IClKernel {
public:
    virtual bool isSetUpSuccessfully()=0;
    virtual bool operator!()=0;
    virtual IClKernel& operator[](uint n)=0;
    virtual IClKernel& operator()(uint, ... )=0;
    virtual IClKernel& operator()(std::vector<IClMemory*>)=0;
    virtual IClKernel& operator()(std::vector<shared_ptr<IClMemory>>)=0;
  
    virtual ~IClKernel(){}
};

