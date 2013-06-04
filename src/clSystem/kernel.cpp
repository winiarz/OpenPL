#include <iostream>
#include <fstream>
#include <stdarg.h>
#include "clSystem/system.h"
#include "clSystem/kernel.h"
#include "clSystem/memory.h"

using namespace std;

bool clKernel::operator!()
{
  return !UtworzonyPoprawnie;
}

clKernel::clKernel(clSystem* s, const char FileName[],const char FunctionName[])
{
  UtworzonyPoprawnie = false;
  system = s;
  global = local = 1;
  is_global_set = false;
  program = CreateProgramFromBinary(system->getContext(),system->getDevice(),FileName);
  if( !program )
  {
    cerr << "Blad odczytu progamu " << FileName << endl;
    return;
  }
  
  kernel = clCreateKernel(program,FunctionName,NULL);
  if( !kernel )
  {
    cerr << "Blad tworzenia kernela (" << FunctionName << "," << FileName << ")" << endl;
    return;
  }
  UtworzonyPoprawnie = true;
}

clKernel::~clKernel()
{
 clReleaseProgram(program); 
 clReleaseKernel(kernel);
}

void clKernel::addArgument(clMemory* memory,uint nr)
{
  cl_int err = clSetKernelArg(kernel,nr,sizeof(*(memory->value())),memory->value());
  if( err != CL_SUCCESS )
  {
    cout << err << CL_INVALID_ARG_SIZE << " Blad przy ustawianiu argumentu " << nr << " kernela" << endl;
  }
}

void clKernel::operator()(uint n, ... )
{
  cl_int err;
  va_list li;
  va_start(li,n);
  for(uint i=0;i<n;i++)
  {
    clMemory* mem = va_arg(li,clMemory*);
    addArgument(mem,i);
  }
  va_end(li);
  err = clEnqueueNDRangeKernel(system->getQueue(),kernel,1,NULL,&global,&local,0,NULL,NULL);
  if( err != CL_SUCCESS )
  {
    cerr << " Blad uruchomienia kernela!! [" << err << "]" << endl;
    return;
  }
  system->wykonaj();
}

clKernel& clKernel::operator[](size_t x)
{
  if(!is_global_set)
  {
    global = x;
    is_global_set = true;
  }
   else
     local = x;
  
}
