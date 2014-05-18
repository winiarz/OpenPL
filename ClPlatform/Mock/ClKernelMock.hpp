
#ifndef __CL_KERNEL_MOCK__
#define __CL_KERNEL_MOCK__

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "IClKernel.hpp"
#include "IClKernelCallStats.hpp"

class ClKernelMock : public IClKernel {
public:
  ClKernelMock() {}
  
  MOCK_METHOD0( isLoaded, bool() );
  MOCK_METHOD0( load, void() );
  MOCK_METHOD0( unload, void() );
  MOCK_METHOD0( isSetUpSuccessfully, bool() );
  virtual bool operator!()
  {
    return !isSetUpSuccessfully(); 
  }
  MOCK_METHOD0( Die, void() );
  virtual ~ClKernelMock() 
  { 
    Die();
  }
  
  virtual IClKernel& operator[](uint)
  {
    return *this;
  }
  virtual IClKernel& operator()(uint, ... )
  {
    return *this;
  }
  virtual IClKernel& operator()(std::vector<ClMemory*> )
  {
      return *this;
  }

  MOCK_METHOD0(getProgram, cl_program());
  MOCK_METHOD0(getStats, IClKernelCallStats&() );
};


#endif
