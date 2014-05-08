#ifndef __I_CL_KERNEL__
#define __I_CL_KERNEL__

typedef unsigned int uint;

class IClKernel {
public:
  virtual bool isLoaded()=0;
  virtual bool isSetUpSuccessfully()=0;
  virtual bool operator!()=0;
  virtual IClKernel& operator[](uint n)=0;
  virtual IClKernel& operator()(uint, ... )=0;
  
  virtual ~IClKernel(){}
};

#endif