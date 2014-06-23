#pragma once

#include "IClDataGenerator.hpp"

class ClDataGeneratorComposite : public IClDataGenerator
{
public:
    ClDataGeneratorComposite(std::vector<std::shared_ptr<IClDataGenerator> >);

    virtual vector<std::shared_ptr<ClMemory> > getData();
    virtual void saveToFile( FILE* );
private:
    vector<std::shared_ptr<IClDataGenerator> > dataGenerators;
};

