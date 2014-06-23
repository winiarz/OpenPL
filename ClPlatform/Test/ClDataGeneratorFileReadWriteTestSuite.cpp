#include "ClDataGeneratorFromFileReader.hpp"
#include "ClRandomFloatArrayGenerator.hpp"
#include "ClDataGeneratorComposite.hpp"
#include <gtest/gtest.h>
#include <cstdio>

using namespace ::testing;

class ClDataGeneratorFileReadWriteTestSuite : public Test
{
public:
    ClDataGeneratorFileReadWriteTestSuite();

    void TearDown();
protected:
    std::string dataGeneratorFilename;
    ClDataGeneratorFromFileReader reader;
};

ClDataGeneratorFileReadWriteTestSuite::ClDataGeneratorFileReadWriteTestSuite() :
    dataGeneratorFilename("dataGenerator")
{
}

void ClDataGeneratorFileReadWriteTestSuite::TearDown()
{
    remove(dataGeneratorFilename.c_str());
}

TEST_F( ClDataGeneratorFileReadWriteTestSuite, writeAndReadFloatArrayGenerator)
{
    ClRandomFloatArrayGenerator floatArrayGenerator(123);

    FILE* file = fopen(dataGeneratorFilename.c_str(),"wb");
    EXPECT_NO_THROW( floatArrayGenerator.saveToFile(file) );
    fclose(file);

    file = fopen(dataGeneratorFilename.c_str(),"rb");
    std::shared_ptr<IClDataGenerator> readGenerator;
    EXPECT_NO_THROW( readGenerator = reader.read(file) );
    fclose(file);

    EXPECT_EQ(typeid(ClRandomFloatArrayGenerator), typeid(*readGenerator));
}

TEST_F( ClDataGeneratorFileReadWriteTestSuite, writeAndreadCompositeGenerator )
{
    std::vector<std::shared_ptr<IClDataGenerator> > generators;
    for ( int i=0; i < 10; i++ ) 
    {
        generators.push_back(std::make_shared<ClRandomFloatArrayGenerator>(10+i));
    }
    ClDataGeneratorComposite compositeGenerator(generators);

    FILE* file = fopen(dataGeneratorFilename.c_str(),"wb");
    EXPECT_NO_THROW( compositeGenerator.saveToFile(file) );
    fclose(file);

    file = fopen(dataGeneratorFilename.c_str(),"rb");
    std::shared_ptr<IClDataGenerator> readGenerator;
    EXPECT_NO_THROW( readGenerator = reader.read(file) );
    fclose(file);

    EXPECT_EQ(typeid(ClDataGeneratorComposite), typeid(*readGenerator));
}

