#include "ClParameterizedKernel.hpp"
#include "ClKernel.hpp"
#include "IClParameter.hpp"
#include "clcc.hpp"

boost::optional<boost::shared_ptr<IClSingleImplementationKernel> > ClParameterizedKernel::getKernel(int paramValue)
{
    if( !parameter->isCorrect(paramValue) )
        return none;

    try
    {
        return optional<boost::shared_ptr<IClSingleImplementationKernel> > (builtKernels.at(paramValue));
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

        boost::shared_ptr<IClSingleImplementationKernel> kernel
            = make_shared<ClKernel>("__temp_kernel_source.clbin",this->getKernelName().c_str());

        if( kernel->isSetUpSuccessfully() )
        {
            builtKernels[paramValue] = kernel;
            return optional<boost::shared_ptr<IClSingleImplementationKernel> >(kernel);
        }
        else
        {
            return none;
        }
    }
}

bool isKernelEqual( const std::pair<int, boost::shared_ptr<IClSingleImplementationKernel> >& kernelWithParameter,
                    boost::shared_ptr<IClSingleImplementationKernel> kernel)
{
    return kernelWithParameter.second == kernel;
}

void ClParameterizedKernel::rejectKernel(boost::shared_ptr<IClSingleImplementationKernel> kernel)
{
   map<int,boost::shared_ptr<IClSingleImplementationKernel> > :: iterator it =
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

boost::shared_ptr<set<int> > ClParameterizedKernel::getNotRejectedParameters()
{
    boost::shared_ptr<set<int> > result = make_shared<set<int> >();
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
