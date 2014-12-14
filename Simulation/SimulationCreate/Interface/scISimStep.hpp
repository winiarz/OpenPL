#pragma once

#include <memory>
#include "IClMemory.hpp"

namespace OPL
{
namespace SimCreate
{
    class ISimStep
    {
    public:
        virtual void execute(std::vector<std::shared_ptr<IClMemory>>) = 0;
        virtual void execute(std::vector<IClMemory*>) = 0;
    };

}
}

