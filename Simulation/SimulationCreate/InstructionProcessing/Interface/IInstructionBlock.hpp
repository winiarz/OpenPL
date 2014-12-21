
#pragma once

#include "boost.hpp"
#include "IInstruction.hpp"

namespace OPL
{
namespace InsPr
{
    class IInstructionBlock : public IInstruction
    {
    public:
        virtual void startElse()
        {}
        virtual void addInstruction(shared_ptr<IInstruction>) = 0;
    };
}
}

