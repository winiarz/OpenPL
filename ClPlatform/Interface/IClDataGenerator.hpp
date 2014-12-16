#pragma once

#include "stl.hpp"

namespace OPL
{
class ClMemory;
}

class IClDataGenerator {
public:
    virtual vector<shared_ptr<OPL::ClMemory> > getData() = 0;
    virtual void saveToFile( FILE* ) = 0;
};

