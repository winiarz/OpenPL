#pragma once

#include "boost.hpp"

namespace OPL
{
namespace SimCreate
{

class ISimStep;

class ISimStepCreator
{
public:
    virtual shared_ptr<ISimStep> create() = 0;
};

}
}

