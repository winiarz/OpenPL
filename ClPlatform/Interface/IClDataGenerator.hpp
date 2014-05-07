#ifndef __I_CL_DATA_GENERATOR__
#define __I_CL_DATA_GENERATOR__

#include "stl.hpp"
#include "boost.hpp"

class ClMemory;

class IClDataGenerator {
public:
    virtual vector<boost::shared_ptr<ClMemory> > getData();
};

#endif

