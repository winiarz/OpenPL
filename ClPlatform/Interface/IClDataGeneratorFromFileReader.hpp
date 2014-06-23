#pragma once

#include "IClDataGenerator.hpp"

class IClDataGeneratorFromFileReader
{
public:
    virtual shared_ptr<IClDataGenerator> read(FILE*) = 0;
};

