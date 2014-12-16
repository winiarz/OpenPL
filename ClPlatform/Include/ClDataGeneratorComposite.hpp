#pragma once

#include "IClDataGenerator.hpp"

namespace OPL
{

class ClDataGeneratorComposite : public IClDataGenerator
{
public:
    ClDataGeneratorComposite(std::vector<shared_ptr<IClDataGenerator> >);

    virtual vector<shared_ptr<ClMemory> > getData();
    virtual void saveToFile( FILE* );
private:
    vector<shared_ptr<IClDataGenerator> > dataGenerators;
};

}

