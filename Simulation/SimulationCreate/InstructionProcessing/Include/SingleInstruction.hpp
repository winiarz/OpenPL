#pragma once

#include "IInstruction.hpp"

namespace InsPr
{
    class SimgleInstruction : IInstruction
    {
    public:
        SimgleInstruction(std::string);
        virtual uint getAlternativesCount();
        virtual std::vector<std::string> getAllAlternatives();
    private:
        std::string instruction;
    };
}

