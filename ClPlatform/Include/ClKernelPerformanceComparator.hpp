#pragma once

#include "IClKernelPerformanceComparator.hpp"
#include "IClDataGenerator.hpp"
#include "IClParameterizedKernel.hpp"
#include "IClock.hpp"

namespace OPL
{

class ClKernelPerformanceComparator : public IClKernelPerformanceComparator {
public:
    ClKernelPerformanceComparator(IClock&);
    virtual bool comparationStep();
    virtual void setDataGenerator( shared_ptr<IClDataGenerator>);
    virtual void addKernel( shared_ptr<IClSingleImplementationKernel> );
    virtual void addParameterizedKernel( shared_ptr<IClParameterizedKernel> );
    virtual optional<shared_ptr<IClSingleImplementationKernel> > getBestKernel();
    virtual void saveToFile( FILE* file );
private:
    IClock& clock;
    optional<shared_ptr<IClDataGenerator> > dataGenerator;
    set<shared_ptr<IClSingleImplementationKernel> > remainingKernels;
    uint bestTime;
    optional<shared_ptr<IClSingleImplementationKernel> > bestKernel;
};

}

