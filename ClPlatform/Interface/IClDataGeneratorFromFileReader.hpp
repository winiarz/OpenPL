#pragma once

#include "boost.hpp"
#include "IClDataGenerator.hpp"

class IClDataGeneratorFromFileReader
{
public:
    virtual std::shared_ptr<IClDataGenerator> read(FILE*) = 0;
};

