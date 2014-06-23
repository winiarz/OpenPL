#pragma once

#include "stl.hpp"

class ClMemory;

class IClDataGenerator {
public:
    virtual vector<shared_ptr<ClMemory> > getData() = 0;
    virtual void saveToFile( FILE* ) = 0;
};

