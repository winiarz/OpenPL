#include "ClParameterizedKernel.hpp"
#include "ClKernel.hpp"
#include "IClParameter.hpp"
#include "clcc.hpp"

boost::optional<std::shared_ptr<IClSingleImplementationKernel> > ClParameterizedKernel::getKernel(int paramValue)
{
    if( !parameter->isCorrect(paramValue) )
        return none;

    try
    {
        std::shared_ptr<IClSingleImplementationKernel> l_result = builtKernels.at(paramValue);
        return boost::optional<std::shared_ptr<IClSingleImplementationKernel> > (l_result);
    }
    catch( out_of_range )
    {
        if( rejectedKernels.find(paramValue) != rejectedKernels.end() )
            return none;

        string kernelSource = this->getSource(paramValue);

        ofstream tempFile("__temp_kernel_source.cl"); // TODO do it without temp file !
        tempFile << kernelSource;
        tempFile.close();
        set<string> includeDirs;
        includeDirs.insert(string("."));
        compile("__temp_kernel_source.cl",includeDirs, "__temp_kernel_source.clbin"); // TODO do not create binary file

        std::shared_ptr<IClSingleImplementationKernel> kernel
            = std::make_shared<ClKernel>("__temp_kernel_source.clbin",this->getKernelName().c_str());

        if( kernel->isSetUpSuccessfully() )
        {
            builtKernels[paramValue] = kernel;
            return optional<std::shared_ptr<IClSingleImplementationKernel> >(kernel);
        }
        else
        {
            return boost::none;
        }
    }
}

bool isKernelEqual( const std::pair<int, std::shared_ptr<IClSingleImplementationKernel> >& kernelWithParameter,
                    std::shared_ptr<IClSingleImplementationKernel> kernel)
{
    return kernelWithParameter.second == kernel;
}

void ClParameterizedKernel::rejectKernel(std::shared_ptr<IClSingleImplementationKernel> kernel)
{
   map<int,std::shared_ptr<IClSingleImplementationKernel> > :: iterator it =
                        std::find_if(builtKernels.begin(),
                                     builtKernels.end(),
                                     boost::bind( isKernelEqual, _1, kernel) );

   if( it != builtKernels.end() )
   {
       rejectedKernels.insert( it->first );
       builtKernels.erase( it );
   }
}

boost::shared_ptr<IClParameter> ClParameterizedKernel::getParameter()
{
    return parameter;
}

std::shared_ptr<set<int> > ClParameterizedKernel::getNotRejectedParameters()
{
    auto result = std::make_shared<set<int> >();
    set<int> allPosible = parameter->getAllPosible();
    std::set_difference( allPosible.begin(), allPosible.end(),
                         rejectedKernels.begin(), rejectedKernels.end(),
                         std::inserter(*result, result->end()));
    return result;
}

ClParameterizedKernel::ClParameterizedKernel(boost::shared_ptr<IClParameter> p_parameter) :
    parameter(p_parameter)
{
}
