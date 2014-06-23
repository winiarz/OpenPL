#pragma once

#include "IKernel.hpp"
#include "Variable.hpp"
#include "InstructionBlock.hpp"

namespace InsPr
{
    class Kernel : public IKernel
    {
    public:
        Kernel(std::string,
               std::vector<std::shared_ptr<IGlobalArrayVariable>>,
               std::shared_ptr<IInstructionBlock>,
               std::vector<std::string> = std::vector<std::string>() );
        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
    private:
        std::string kernelName;
        std::vector<std::shared_ptr<IGlobalArrayVariable>> arguments;
        std::shared_ptr<IInstructionBlock> instructions;
        std::vector<std::string> includes;
    };
}

