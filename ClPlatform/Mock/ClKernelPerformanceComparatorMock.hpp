#pragma once

#include "IClKernelPerformanceComparator.hpp"

#include <gmock/gmock.h>

namespace OPL
{

class ClKernelPerformanceComparatorMock : public IClKernelPerformanceComparator {
public:
    MOCK_METHOD0( comparationStep, bool() );
    MOCK_METHOD1( setDataGenerator, void (shared_ptr<IClDataGenerator>) );
    MOCK_METHOD1( addKernel, void(shared_ptr<IClSingleImplementationKernel> ) );
    MOCK_METHOD1( addParameterizedKernel, void(shared_ptr<IClParameterizedKernel>) );
    MOCK_METHOD0( getBestKernel, optional<shared_ptr<IClSingleImplementationKernel> >() );
    MOCK_METHOD1( saveToFile, void( FILE* ) );
};

}

