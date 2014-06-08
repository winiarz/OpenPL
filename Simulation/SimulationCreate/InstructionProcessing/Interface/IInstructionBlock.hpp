
#pragma once

#include "boost.hpp"
#include "IInstruction.hpp"

namespace InsPr
{
    class IInstructionBlock : public IInstruction
    {
    public:
        virtual void addInstruction(boost::shared_ptr<IInstruction>) = 0;
    };
}

