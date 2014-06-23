#pragma once

#include "boost.hpp"
#include "IClDataGeneratorFromFileReader.hpp"

class ClDataGeneratorFromFileReader : public IClDataGeneratorFromFileReader
{
public:
    virtual shared_ptr<IClDataGenerator> read(FILE*);
private:
    shared_ptr<IClDataGenerator> readFloatArrayGenerator(FILE*);
    shared_ptr<IClDataGenerator> readComposizeOfGenerators(FILE*);
};

