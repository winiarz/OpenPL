#pragma once

#include "boost.hpp"
#include "IInstructionBlock.hpp"

namespace OPL
{
namespace InsPr
{
    class InstructionBlock : public IInstructionBlock
    {
    public:
        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(shared_ptr<IInstruction>);
    private:
        std::vector<shared_ptr<IInstruction> > instructions;
    };
}
}

