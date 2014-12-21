#pragma once

#include "IKernel.hpp"
#include "Variable.hpp"
#include "InstructionBlock.hpp"

namespace OPL
{
namespace InsPr
{
    class Kernel : public IKernel
    {
    public:
        Kernel(std::string,
               std::vector<shared_ptr<IGlobalArrayVariable>>,
               shared_ptr<IInstructionBlock>,
               std::vector<std::string> = std::vector<std::string>() );
        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
    private:
        std::string kernelName;
        std::vector<shared_ptr<IGlobalArrayVariable>> arguments;
        shared_ptr<IInstructionBlock> instructions;
        std::vector<std::string> includes;
    };
}
}

