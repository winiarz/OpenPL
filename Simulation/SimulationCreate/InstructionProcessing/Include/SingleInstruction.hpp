#pragma once

#include "IInstruction.hpp"

namespace OPL
{
namespace InsPr
{
    class SingleInstruction : public IInstruction
    {
    public:
        SingleInstruction(std::string);
        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
    private:
        std::string instruction;
    };
}
}

