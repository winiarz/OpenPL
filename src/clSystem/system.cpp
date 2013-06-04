#include <iostream>
#include "clSystem/system.h"


clSystem::clSystem()
{
  UtworzonyPoprawnie = false;
  cl_uint pobrane_platform_nb;
  clGetPlatformIDs(1, &platforma, &pobrane_platform_nb);
  if(pobrane_platform_nb <= 0)
  {
    std::cerr << "Blad clGetPlatformIDs " << pobrane_platform_nb << std::endl;
    return;
  }
  cl_uint pobrane_device_nb;
  clGetDeviceIDs(platforma,CL_DEVICE_TYPE_GPU,1,&urzadzenie,&pobrane_device_nb);
  if(pobrane_device_nb <= 0)
  {
    std::cerr << "Blad clGetDeviceIDs " << pobrane_device_nb << std::endl;
    return;
  }
  kontekst = clCreateContext(NULL,1,&urzadzenie,NULL,NULL,NULL);
  if(kontekst == NULL)
  {
    std::cerr << "Blad clCreateContext " << std::endl;
    return;
  }
  cl_int error;
  kolejka = clCreateCommandQueue(kontekst,urzadzenie,CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE,&error);
  if(error != CL_SUCCESS)
  {
    std::cerr << "Blad clCreateCommandQueue " << error << std::endl;
    return;
  }
  
  
  UtworzonyPoprawnie = true;
}

clSystem::~clSystem()
{ 
  clReleaseCommandQueue(kolejka);
  clReleaseContext(kontekst);
}

bool clSystem::operator!()
{
  return !UtworzonyPoprawnie;
}

cl_context clSystem::getContext()
{
  return kontekst;
}

cl_device_id clSystem::getDevice()
{
  return urzadzenie;
}

void clSystem::wykonaj()
{
  clFinish(kolejka);
}

cl_command_queue clSystem::getQueue()
{
  return kolejka;
}