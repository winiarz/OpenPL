#pragma once

#include "IClKernelPerformanceComparator.hpp"

#include <gmock/gmock.h>

class ClKernelPerformanceComparatorMock : public IClKernelPerformanceComparator {
public:
    MOCK_METHOD0( comparationStep, bool() );
    MOCK_METHOD1( setDataGenerator, void (boost::shared_ptr<IClDataGenerator>) );
    MOCK_METHOD1( addKernel, void(boost::shared_ptr<IClSingleImplementationKernel> ) );
    MOCK_METHOD1( addParameterizedKernel, void(boost::shared_ptr<IClParameterizedKernel>) );
    MOCK_METHOD0( getBestKernel, optional<boost::shared_ptr<IClSingleImplementationKernel> >() );
    MOCK_METHOD1( saveToFile, void( FILE* ) );
};

