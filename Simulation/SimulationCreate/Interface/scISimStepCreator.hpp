#pragma once

#include <memory>

namespace OPL
{
namespace SimCreate
{

class ISimStep;

class ISimStepCreator
{
public:
    virtual std::shared_ptr<ISimStep> create() = 0;
};

}
}

