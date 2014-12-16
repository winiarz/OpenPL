#pragma once

#include "ClMemory.hpp"

template<typename T>
class ClArrayMemory : public OPL::ClMemory {
public:
  ClArrayMemory(uint n,ClMemoryCreation clMemoryCreation = CL_MEMORY_ALLOC ) :
	OPL::ClMemory(OPL::calculateSize(n,clMemoryCreation,sizeof(T)), clMemoryCreation)
  {
  }

  void copyIn (T* data, uint start, uint size)
  {
    OPL::ClMemory::copyIn(data, sizeof(T)*start, sizeof(T)*size);
  }

  void copyOut(T* data, uint start, uint size)
  {
    OPL::ClMemory::copyOut(data, sizeof(T)*start, sizeof(T)*size);
  }

};



