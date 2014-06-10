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
    virtual boost::shared_ptr<ISimStep> create() = 0;
};

}
}

