#pragma once

#include "IClDataGenerator.hpp"

class ClDataGeneratorComposite : public IClDataGenerator
{
public:
    ClDataGeneratorComposite(std::vector<shared_ptr<IClDataGenerator> >);

    virtual vector<shared_ptr<OPL::ClMemory> > getData();
    virtual void saveToFile( FILE* );
private:
    vector<shared_ptr<IClDataGenerator> > dataGenerators;
};

