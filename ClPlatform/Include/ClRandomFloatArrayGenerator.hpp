#ifndef __CL_RANDOM_FLOAT_ARRAY_GENERATOR__
#define __CL_RANDOM_FLOAT_ARRAY_GENERATOR__

#include "IClDataGenerator.hpp"

class ClRandomFloatArrayGenerator : public IClDataGenerator
{
public:
    ClRandomFloatArrayGenerator(uint);
    virtual vector<boost::shared_ptr<ClMemory> > getData();
private:
    const uint arraySize;
};

#endif

