#ifndef __I_CL_DATA_GENERATOR_FROM_FILE_READER__
#define __I_CL_DATA_GENERATOR_FROM_FILE_READER__

#include "boost.hpp"
#include "IClDataGenerator.hpp"

class IClDataGeneratorFromFileReader
{
public:
    virtual boost::shared_ptr<IClDataGenerator> read(FILE*) = 0;
};

#endif

