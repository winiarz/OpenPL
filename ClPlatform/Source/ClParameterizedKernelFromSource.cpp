#include "ClParameterizedKernelFromSource.hpp"

namespace OPL
{

ClParameterizedKernelFromSource::ClParameterizedKernelFromSource(shared_ptr<IClParameter> p_parameter,
                                                                 string p_fileName,
                                                                 string p_kernelName,
                                                                 string p_paramName) :
    ClParameterizedKernel(p_parameter),
    fileName(p_fileName),
    kernelName(p_kernelName),
    paramName(p_paramName)
{
    setupSuccessfully = false;

    ifstream file(fileName);
    if( !file )
    {
        return;
    }
    file.close();

    setupSuccessfully = true;
}

string ClParameterizedKernelFromSource::getSource(int param)
{
    if( !setupSuccessfully )
        return string();
    ifstream file(fileName);
    if( !file )
        return string();

    std::ostringstream sstreamParam;
    sstreamParam << param;
    string stringParamValue = sstreamParam.str();

    std::ostringstream fileText;
    while( !file.eof() )
    {
        char line[1024];
        file.getline(line, 1024);
        string lineStr = string(line);

        size_t f=lineStr.find(paramName);
        while( f != std::string::npos )
        {
            lineStr.replace(f, paramName.length(), stringParamValue);
            f = lineStr.find(paramName);
        }

        fileText << lineStr << std::endl;
    }

    return fileText.str();
}

string ClParameterizedKernelFromSource::getKernelName()
{
    return kernelName;
}

}

