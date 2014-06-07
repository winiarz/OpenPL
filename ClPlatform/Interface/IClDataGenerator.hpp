#pragma once

#include "stl.hpp"
#include "boost.hpp"

class ClMemory;

class IClDataGenerator {
public:
    virtual vector<boost::shared_ptr<ClMemory> > getData() = 0;
    virtual void saveToFile( FILE* ) = 0;
};

