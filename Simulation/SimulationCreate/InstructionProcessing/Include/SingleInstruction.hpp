#pragma once

#include "IInstruction.hpp"

namespace InsPr
{
    class SingleInstruction : IInstruction
    {
    public:
        SingleInstruction(std::string);
        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
    private:
        std::string instruction;
    };
}

