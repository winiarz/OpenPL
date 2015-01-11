#pragma once

#include <vector>
#include <memory>
#include "IInstruction.hpp"

namespace OPL
{
namespace InsPr
{
    class AlternativeInstruction : public IInstruction
    {
    public:
        AlternativeInstruction(std::vector<std::shared_ptr<IInstruction>>);
        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
    private:
        std::vector<std::shared_ptr<IInstruction>> alternatives;
    };
}
}

