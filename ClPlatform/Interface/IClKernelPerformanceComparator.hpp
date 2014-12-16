#pragma once

#include "boost.hpp"
#include "IClSingleImplementationKernel.hpp"

class IClParameterizedKernel;

namespace OPL
{
class IClDataGenerator;

class IClKernelPerformanceComparator {
public:
    virtual bool comparationStep()=0;
    virtual void setDataGenerator( shared_ptr<IClDataGenerator>)=0;
    virtual void addKernel( shared_ptr<IClSingleImplementationKernel> )=0;
    virtual void addParameterizedKernel( shared_ptr<IClParameterizedKernel> )=0;
    virtual optional<shared_ptr<IClSingleImplementationKernel> > getBestKernel()=0;
    virtual void saveToFile( FILE* file ) = 0;
};

}

