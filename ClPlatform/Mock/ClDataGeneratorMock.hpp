#pragma once

#include "IClDataGenerator.hpp"
#include<gtest/gtest.h>
#include<gmock/gmock.h>

namespace OPL
{

class ClDataGeneratorMock : public IClDataGenerator {
public:
    MOCK_METHOD0( getData, vector<shared_ptr<OPL::ClMemory> >());
    MOCK_METHOD1( saveToFile, void(FILE*));
};

}

