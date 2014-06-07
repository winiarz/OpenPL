#pragma once

#include "boost.hpp"
#include "IClDataGeneratorFromFileReader.hpp"

class ClDataGeneratorFromFileReader : public IClDataGeneratorFromFileReader
{
public:
    virtual boost::shared_ptr<IClDataGenerator> read(FILE*);
private:
    boost::shared_ptr<IClDataGenerator> readFloatArrayGenerator(FILE*);
    boost::shared_ptr<IClDataGenerator> readComposizeOfGenerators(FILE*);
};

