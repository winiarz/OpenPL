#pragma once

#include "IClDataGenerator.hpp"

namespace OPL
{

class IClDataGeneratorFromFileReader
{
public:
    virtual shared_ptr<IClDataGenerator> read(FILE*) = 0;
};

}

