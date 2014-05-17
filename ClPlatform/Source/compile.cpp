#include "clcc.hpp"
#include "ClPlatform.hpp"
#include "logs.hpp"
#include "ClKernelSaver.hpp"
#include "ClKernel.hpp"

int compile(const char input_file[],set<string>  includeDirectories,const char output_file[])
{
  ClPlatform& platform = ClPlatform::getPlatform();
  char temporary_file[200] = "__CLLC_TEMP_COMPILATION_FILE.cl";
  findInclude(input_file,temporary_file,includeDirectories);
  
  cl_program program = CreateProgram(platform.getContext(),platform.getDevice(), temporary_file);
  if( !program )
    return 1;
  boost::shared_ptr<IClKernel> kernel = boost::make_shared<ClKernel>( program );
  try
  {
      ClKernelSaver().saveKernel( kernel, std::string(output_file) );
  }
  catch ( ClError ) 
  {
      cout << "Save kernel file error\n";
  }
  remove(temporary_file);
  return 0;
}
