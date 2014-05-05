#include "ClParameterizedKernelFromSource.hpp"

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
        string line;
        file >> line;

        size_t f=line.find(paramName);;
        while( f != std::string::npos )
        {
            line.replace(f, paramName.length(), stringParamValue);
            f = line.find(paramName);
        }

        fileText << line;
    }

    return fileText.str();
}

string ClParameterizedKernelFromSource::getKernelName()
{
    return kernelName;
}
