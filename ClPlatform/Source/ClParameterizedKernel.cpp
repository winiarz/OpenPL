#include "ClParameterizedKernel.hpp"
#include "ClKernel.hpp"
#include "IClParameter.hpp"
#include "OpenClCompilerWithPreprocessor.hpp"
#include "ClIncludePreprocessor.hpp"
#include "OpenClCompiler.hpp"
#include "clcc.hpp"
#include "logs.hpp"

namespace OPL
{

boost::optional<shared_ptr<OPL::IClSingleImplementationKernel> > ClParameterizedKernel::getKernel(int paramValue)
{
    if( !parameter->isCorrect(paramValue) )
        return none;

    try
    {
        shared_ptr<OPL::IClSingleImplementationKernel> l_result = builtKernels.at(paramValue);
        return boost::optional<shared_ptr<OPL::IClSingleImplementationKernel> > (l_result);
    }
    catch( out_of_range )
    {
        if( rejectedKernels.find(paramValue) != rejectedKernels.end() )
            return none;

        string kernelSource = this->getSource(paramValue);

        vector<string> includeDirs = {"."};
        OPL::OpenClCompilerWithPreprocessor compiler(std::make_shared<OPL::OpenClCompiler>(),
                                                     std::make_shared<OPL::ClIncludePreprocessor>(includeDirs));

        auto program = compiler.compile(kernelSource);

        shared_ptr<OPL::IClSingleImplementationKernel> kernel = std::make_shared<OPL::ClKernel>(program, this->getKernelName());

        if( kernel->isSetUpSuccessfully() )
        {
            builtKernels[paramValue] = kernel;
            return optional<shared_ptr<OPL::IClSingleImplementationKernel> >(kernel);
        }
        else
        {
            return boost::none;
        }
    }
}

bool isKernelEqual( const std::pair<int, shared_ptr<OPL::IClSingleImplementationKernel> >& kernelWithParameter,
                    shared_ptr<OPL::IClSingleImplementationKernel> kernel)
{
    return kernelWithParameter.second == kernel;
}

void ClParameterizedKernel::rejectKernel(shared_ptr<OPL::IClSingleImplementationKernel> kernel)
{
   map<int,shared_ptr<OPL::IClSingleImplementationKernel> > :: iterator it =
                        std::find_if(builtKernels.begin(),
                                     builtKernels.end(),
                                     boost::bind( isKernelEqual, _1, kernel) );

   if( it != builtKernels.end() )
   {
       rejectedKernels.insert( it->first );
       builtKernels.erase( it );
   }
}

shared_ptr<IClParameter> ClParameterizedKernel::getParameter()
{
    return parameter;
}

shared_ptr<set<int> > ClParameterizedKernel::getNotRejectedParameters()
{
    auto result = make_shared<set<int> >();
    set<int> allPosible = parameter->getAllPosible();
    std::set_difference( allPosible.begin(), allPosible.end(),
                         rejectedKernels.begin(), rejectedKernels.end(),
                         std::inserter(*result, result->end()));
    return result;
}

ClParameterizedKernel::ClParameterizedKernel(shared_ptr<IClParameter> p_parameter) :
    parameter(p_parameter)
{
}

}

