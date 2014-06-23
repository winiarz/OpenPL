#pragma once

#include "boost.hpp"
#include "IClSingleImplementationKernel.hpp"

class IClDataGenerator;
class IClParameterizedKernel;

class IClKernelPerformanceComparator {
public:
    virtual bool comparationStep()=0;
    virtual void setDataGenerator( boost::shared_ptr<IClDataGenerator>)=0;
    virtual void addKernel( std::shared_ptr<IClSingleImplementationKernel> )=0;
    virtual void addParameterizedKernel( boost::shared_ptr<IClParameterizedKernel> )=0;
    virtual optional<std::shared_ptr<IClSingleImplementationKernel> > getBestKernel()=0;
    virtual void saveToFile( FILE* file ) = 0;
};

