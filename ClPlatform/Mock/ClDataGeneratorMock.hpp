#ifndef __CL_DATA_GENERATOR_MOCK__
#define __CL_DATA_GENERATOR_MOCK__

#include "IClDataGenerator.hpp"
#include<gtest/gtest.h>
#include<gmock/gmock.h>

class ClDataGeneratorMock : public IClDataGenerator {
public:
    MOCK_METHOD0( getData, vector<boost::shared_ptr<ClMemory> >());
    MOCK_METHOD1( saveToFile, void(FILE*));
};

#endif

