#pragma once

#include "boost.hpp"
#include "IInstructionBlock.hpp"

namespace InsPr
{
    class InstructionBlock : public IInstructionBlock
    {
    public:
        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(boost::shared_ptr<IInstruction>);
    private:
        std::vector<boost::shared_ptr<IInstruction> > instructions;
    };
}

