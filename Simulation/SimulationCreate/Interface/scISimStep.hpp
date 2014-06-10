#pragma once

#include "ClMemory.hpp"

namespace OPL
{
namespace SimCreate
{
    class ISimStep
    {
    public:
        virtual void execute(std::vector<boost::shared_ptr<ClMemory>>) = 0;
    };

}
}

