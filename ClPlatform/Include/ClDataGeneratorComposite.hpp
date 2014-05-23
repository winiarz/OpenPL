#ifndef __CL_DATA_GENERATOR_COMPOSITE__
#define __CL_DATA_GENERATOR_COMPOSITE__


#include "IClDataGenerator.hpp"

class ClDataGeneratorComposite : public IClDataGenerator
{
public:
    ClDataGeneratorComposite(std::vector<boost::shared_ptr<IClDataGenerator> >);

    virtual vector<boost::shared_ptr<ClMemory> > getData();
    virtual void saveToFile( FILE* );
private:
    vector<boost::shared_ptr<IClDataGenerator> > dataGenerators;
};

#endif
