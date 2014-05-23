#include "ClDataGeneratorComposite.hpp"

ClDataGeneratorComposite::ClDataGeneratorComposite(std::vector<boost::shared_ptr<IClDataGenerator> > p_dataGenerators) :
    dataGenerators(p_dataGenerators)
{
}

vector<boost::shared_ptr<ClMemory> > ClDataGeneratorComposite::getData()
{
    vector<boost::shared_ptr<ClMemory> > result;

    std::vector<boost::shared_ptr<IClDataGenerator> >::iterator i;
    for ( i = dataGenerators.begin(); i != dataGenerators.end(); ++i)
    {
        vector<boost::shared_ptr<ClMemory> > data = (*i)->getData();

        result.insert( result.end(), data.begin(), data.end());
    }

    return result;
}

void ClDataGeneratorComposite::saveToFile( FILE* file )
{
    char prefix = 'C';
    fwrite(&prefix, sizeof(char), 1, file);

    uint componentsCount = dataGenerators.size();
    fwrite(&componentsCount, sizeof(uint), 1, file);

    std::vector<boost::shared_ptr<IClDataGenerator> >::iterator i;
    for ( i = dataGenerators.begin(); i != dataGenerators.end(); ++i)
    {
        (*i)->saveToFile(file);
    }
}

