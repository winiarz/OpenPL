#pragma once

#include "boost.hpp"
#include "IClDataGenerator.hpp"

class IClDataGeneratorFromFileReader
{
public:
    virtual boost::shared_ptr<IClDataGenerator> read(FILE*) = 0;
};

