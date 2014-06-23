#pragma once

#include "IClDataGenerator.hpp"

class IClDataGeneratorFromFileReader
{
public:
    virtual std::shared_ptr<IClDataGenerator> read(FILE*) = 0;
};

