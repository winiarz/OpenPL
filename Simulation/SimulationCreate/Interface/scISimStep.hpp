#pragma once

#include "ClMemory.hpp"

namespace OPL
{
namespace SimCreate
{
    class ISimStep
    {
    public:
        virtual void execute(std::vector<shared_ptr<ClMemory>>) = 0;
        virtual void execute(std::vector<ClMemory*>) = 0;
    };

}
}

