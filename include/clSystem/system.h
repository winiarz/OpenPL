

#ifndef __clSystem__
#define __clSystem__

#include <CL/cl.h>

class clKernel;
class clMemory;

class clSystem {
public:
  
  clSystem();
  ~clSystem();
  bool operator!();
  cl_context getContext();
  cl_device_id getDevice();
  cl_command_queue getQueue();
  void wykonaj();
private:
  bool UtworzonyPoprawnie;
  cl_platform_id platforma;
  cl_device_id urzadzenie;
  cl_context kontekst;
  cl_command_queue kolejka;
};

cl_program CreateProgram(cl_context context, cl_device_id device, const char* fileName);
bool SaveProgramBinary(cl_program program, cl_device_id device, const char* fileName);
cl_program CreateProgramFromBinary(cl_context context, cl_device_id device, const char* fileName);

#include "memory.h"

#endif
