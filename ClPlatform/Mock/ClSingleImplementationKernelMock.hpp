#pragma once

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "IClSingleImplementationKernel.hpp"
#include "IClKernelCallStats.hpp"

namespace OPL
{

class ClSingleImplementationKernelMock : public IClSingleImplementationKernel {
public:
  MOCK_METHOD0( isLoaded, bool() );
  MOCK_METHOD0( load, void() );
  MOCK_METHOD0( unload, void() );
  MOCK_METHOD0( isSetUpSuccessfully, bool() );
  virtual bool operator!()
  {
    return !isSetUpSuccessfully(); 
  }
  MOCK_METHOD0( Die, void() );
  virtual ~ClSingleImplementationKernelMock() 
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
  virtual IClKernel& operator()(std::vector<OPL::IClMemory*> )
  {
      return *this;
  }
  virtual IClKernel& operator()(std::vector<shared_ptr<OPL::IClMemory>> )
  {
      return *this;
  }

  MOCK_METHOD0(getProgram, cl_program());
  MOCK_METHOD0(getStats, OPL::IClKernelCallStats&() );
};

}

