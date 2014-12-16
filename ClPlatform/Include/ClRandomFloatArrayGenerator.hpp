#pragma once

#include "IClDataGenerator.hpp"

namespace OPL
{

class ClRandomFloatArrayGenerator : public IClDataGenerator
{
public:
    ClRandomFloatArrayGenerator(uint);
    virtual vector<shared_ptr<ClMemory> > getData();
    virtual void saveToFile( FILE* );
private:
    const uint arraySize;
};

}

