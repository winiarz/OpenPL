
#ifndef __clMemory__
#define __clMemory__

#include <CL/cl.h>

class clMemory {
private:
  bool utworzonyPoprawnie;
  cl_mem memory;
  size_t rozmiar;
  clSystem* system;
public:
  ~clMemory();
  clMemory(clSystem*,size_t,cl_mem_flags);
  bool operator!();
  size_t size();
  cl_mem* value();
  
  static const int in=1;
  static const int out=2;
  bool memcpy(void*,int);
};

#endif
