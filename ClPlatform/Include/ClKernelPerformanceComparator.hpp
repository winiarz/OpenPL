#pragma once

#include "IClKernelPerformanceComparator.hpp"
#include "IClDataGenerator.hpp"
#include "IClParameterizedKernel.hpp"
#include "IClock.hpp"

class ClKernelPerformanceComparator : public IClKernelPerformanceComparator {
public:
    ClKernelPerformanceComparator(IClock&);
    virtual bool comparationStep();
    virtual void setDataGenerator( boost::shared_ptr<IClDataGenerator>);
    virtual void addKernel( std::shared_ptr<IClSingleImplementationKernel> );
    virtual void addParameterizedKernel( boost::shared_ptr<IClParameterizedKernel> );
    virtual optional<std::shared_ptr<IClSingleImplementationKernel> > getBestKernel();
    virtual void saveToFile( FILE* file );
private:
    IClock& clock;
    optional<boost::shared_ptr<IClDataGenerator> > dataGenerator;
    set<std::shared_ptr<IClSingleImplementationKernel> > remainingKernels;
    uint bestTime;
    optional<std::shared_ptr<IClSingleImplementationKernel> > bestKernel;
};

