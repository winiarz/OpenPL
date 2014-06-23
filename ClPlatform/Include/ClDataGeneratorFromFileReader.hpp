#pragma once

#include "boost.hpp"
#include "IClDataGeneratorFromFileReader.hpp"

class ClDataGeneratorFromFileReader : public IClDataGeneratorFromFileReader
{
public:
    virtual std::shared_ptr<IClDataGenerator> read(FILE*);
private:
    std::shared_ptr<IClDataGenerator> readFloatArrayGenerator(FILE*);
    std::shared_ptr<IClDataGenerator> readComposizeOfGenerators(FILE*);
};

