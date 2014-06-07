#pragma once

#include "boost.hpp"
#include "IInstruction.hpp"

namespace InsPr
{
    class InstructionBlock : public IInstruction
    {
    public:
        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(boost::shared_ptr<IInstruction>);
    private:
        std::vector<boost::shared_ptr<IInstruction> > instructions;
    };
}

