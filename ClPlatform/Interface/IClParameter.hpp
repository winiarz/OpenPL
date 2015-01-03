#pragma once
#include <set>

namespace OPL
{

class IClParameter {
public:
    virtual bool isCorrect(int) = 0;
    virtual std::set<int> getAllPosible() = 0;
};

}

