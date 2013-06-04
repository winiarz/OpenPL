
#ifndef __clKernel__
#define __clKernel__

#include <CL/cl.h>

class clKernel {
public:
  
  ~clKernel();
  clKernel(clSystem*,const char[],const char[]);
  bool operator!();
  void operator()(uint,...);
  clKernel& operator[](size_t);
private:
  bool UtworzonyPoprawnie;
  size_t global;
  size_t local;
  bool is_global_set;
  
  clSystem* system;
  cl_program program;
  cl_kernel kernel;
  friend class clSystem;
  void addArgument(clMemory*,uint);
};

#endif
