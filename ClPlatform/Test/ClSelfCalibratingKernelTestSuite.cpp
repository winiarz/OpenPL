#include <gtest/gtest.h>
#include "ClSelfCalibratingKernel.hpp"
#include "ClKernelPerformanceComparator.hpp"
#include "ClRandomFloatArrayGenerator.hpp"
#include "ClSelfCalibratingKernelFromFileReader.hpp"
#include "ClDataGeneratorFromFileReader.hpp"
#include "ClKernelFromBinaryLoader.hpp"
#include "Clock.hpp"

using namespace ::testing;

class ClSelfCalibratingKernelTestSuite : public Test
{
public:
    ClSelfCalibratingKernelTestSuite();
    void TearDown();
protected:
    std::string kernelFilename;
};

ClSelfCalibratingKernelTestSuite::ClSelfCalibratingKernelTestSuite() :
    kernelFilename("test.sck")
{
}

void ClSelfCalibratingKernelTestSuite::TearDown()
{
    //remove( kernelFilename.c_str() );
}

TEST_F( ClSelfCalibratingKernelTestSuite, saveAndLoad_selfCalibratingKernel )
{
    Clock clock;
    boost::shared_ptr<ClKernelPerformanceComparator> performanceComparator
        = boost::make_shared<ClKernelPerformanceComparator>(clock);

    boost::shared_ptr<IClDataGenerator> dataGenerator =
        boost::make_shared<ClRandomFloatArrayGenerator>(10);

    performanceComparator->setDataGenerator( dataGenerator );

    ClSelfCalibratingKernel sut(performanceComparator);
    
    ASSERT_NO_THROW( sut.saveToFile( kernelFilename ) );

    boost::shared_ptr<IClDataGeneratorFromFileReader> dataGeneratorReader
        = boost::make_shared<ClDataGeneratorFromFileReader>();

    boost::shared_ptr<ClKernelFromBinaryLoader> kernelLoader
        = boost::make_shared<ClKernelFromBinaryLoader>();

    ClSelfCalibratingKernelFromFileReader reader( dataGeneratorReader, kernelLoader, clock );
    ASSERT_NO_THROW( reader.read(kernelFilename) );
}

