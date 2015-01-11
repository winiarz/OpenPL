
#pragma once

#include <memory>
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
        virtual void addInstruction(std::shared_ptr<IInstruction>) = 0;
    };
}
}

