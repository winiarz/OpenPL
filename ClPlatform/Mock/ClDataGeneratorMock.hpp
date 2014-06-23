#pragma once

#include "IClDataGenerator.hpp"
#include<gtest/gtest.h>
#include<gmock/gmock.h>

class ClDataGeneratorMock : public IClDataGenerator {
public:
    MOCK_METHOD0( getData, vector<std::shared_ptr<ClMemory> >());
    MOCK_METHOD1( saveToFile, void(FILE*));
};

