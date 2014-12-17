#pragma once

#include "ClMemory.hpp"

namespace OPL
{

template<typename T>
class ClArrayMemory : public ClMemory {
public:
  ClArrayMemory(uint n,ClMemoryCreation clMemoryCreation = CL_MEMORY_ALLOC ) :
	ClMemory(calculateSize(n,clMemoryCreation,sizeof(T)), clMemoryCreation)
  {
  }

  void copyIn (T* data, uint start, uint size)
  {
    ClMemory::copyIn(data, sizeof(T)*start, sizeof(T)*size);
  }

  void copyOut(T* data, uint start, uint size)
  {
    ClMemory::copyOut(data, sizeof(T)*start, sizeof(T)*size);
  }

};

}

