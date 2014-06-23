#pragma once

#include "boost.hpp"
#include "IFunction.hpp"
#include "IVariable.hpp"
#include "InstructionBlock.hpp"

namespace InsPr
{
    class Function : public IFunction
    {
    public:
        Function(std::string,
                 std::vector<shared_ptr<IVariable>>,
                 std::shared_ptr<InstructionBlock>);
        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
    private:
        std::string functionName;
        std::vector<shared_ptr<IVariable>> arguments;
        std::shared_ptr<InstructionBlock> instructions;
    };
}

