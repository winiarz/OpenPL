#pragma once

#include <vector>
#include "IInstructionBlock.hpp"
using std::shared_ptr;

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

