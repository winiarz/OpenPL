#include "clSystem/system.h"
#include <iostream>
using namespace std;

clMemory::clMemory(clSystem* s,size_t size,cl_mem_flags flags)
{
  system = s;
  utworzonyPoprawnie = false;
  rozmiar = size;
  memory = clCreateBuffer(system->getContext(),flags,size,NULL,NULL);
  if( !memory )
  {
    cerr << "Blad tworzenia pamieci" << endl;
    return;
  }
  utworzonyPoprawnie = true;
}

bool clMemory::operator!()
{
  return !utworzonyPoprawnie;
}

size_t clMemory::size()
{
  return rozmiar;
}

cl_mem* clMemory::value()
{
  return &memory;
}

clMemory::~clMemory()
{
  cl_uint err = clReleaseMemObject(memory);
  if(err != CL_SUCCESS )
    cerr << "Blad zwalninia pamieci!!!\n";
}

bool clMemory::memcpy(void* value,int dir)
{
  cl_int err;
  switch(dir)
  {
    case in:
      err = clEnqueueWriteBuffer(system->getQueue(),memory,CL_TRUE,0,rozmiar,value,0,NULL,NULL);
      break;
    case out:
      err = clEnqueueReadBuffer(system->getQueue(),memory,CL_TRUE,0,rozmiar,value,0,NULL,NULL);
      break;
    default:
      cerr << "Niernany parametr " << dir << " dla metody clMemory::memcpy" << endl;
      return false;
      break;
  }
  if( err != CL_SUCCESS )
  {
    cerr << "Blad przy kopiowaniu clMemory::memcpy" << endl;
    return false;
  }
  return true;
}
