#include "ClDataGeneratorComposite.hpp"
#include "ClError.hpp"

namespace OPL
{

ClDataGeneratorComposite::ClDataGeneratorComposite(std::vector<shared_ptr<IClDataGenerator> > p_dataGenerators) :
    dataGenerators(p_dataGenerators)
{
}

vector<shared_ptr<ClMemory> > ClDataGeneratorComposite::getData()
{
    vector<shared_ptr<ClMemory> > result;

    std::vector<shared_ptr<IClDataGenerator> >::iterator i;
    for ( i = dataGenerators.begin(); i != dataGenerators.end(); ++i)
    {
        vector<shared_ptr<ClMemory> > data = (*i)->getData();

        result.insert( result.end(), data.begin(), data.end());
    }

    return result;
}

void ClDataGeneratorComposite::saveToFile( FILE* file )
{
    char prefix = 'C';
    size_t writtenBytes = fwrite(&prefix, sizeof(char), 1, file);
    if ( writtenBytes < 1 )
        throw FILE_WRITE_ERROR;

    uint componentsCount = dataGenerators.size();
    writtenBytes = fwrite(&componentsCount, sizeof(uint), 1, file);
    if ( writtenBytes < 1 )
        throw FILE_WRITE_ERROR;

    for ( auto i = dataGenerators.begin(); i != dataGenerators.end(); ++i)
    {
        (*i)->saveToFile(file);
    }
}

}

