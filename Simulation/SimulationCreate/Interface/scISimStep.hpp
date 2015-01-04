#pragma once

#include <memory>
#include <vector>

namespace OPL
{
class IClMemory;

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

