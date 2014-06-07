#pragma once

#include "IInstruction.hpp"

namespace InsPr
{
    class SimgleInstruction : IInstruction
    {
    public:
        SimgleInstruction(std::string);
        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
    private:
        std::string instruction;
    };
}

