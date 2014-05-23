#include "ClDataGeneratorFromFileReader.hpp"
#include "ClRandomFloatArrayGenerator.hpp"
#include "ClDataGeneratorComposite.hpp"
#include "ClError.hpp"
#include "logs.hpp"

boost::shared_ptr<IClDataGenerator> ClDataGeneratorFromFileReader::read(FILE* file)
{
    char prefix;
    size_t readBytes = fread(&prefix, sizeof(char), 1, file);
    if ( readBytes < 1 ) 
        throw FILE_READ_ERROR;

    switch (prefix) 
    {
    case 'C':
        return readComposizeOfGenerators(file);
        break;
    case 'F':
        return readFloatArrayGenerator(file);
        break;
    default:
        ERROR << "unknown data generator type = '" << prefix << "'";
        throw INCORRECT_DATA_GENERATOR_FILE;
    }
    return boost::shared_ptr<IClDataGenerator>();
}

boost::shared_ptr<IClDataGenerator> ClDataGeneratorFromFileReader::readFloatArrayGenerator(FILE* file)
{
    uint arraySize;
    size_t readBytes = fread( &arraySize, sizeof(uint), 1, file);
    if ( readBytes < 1 ) 
        throw FILE_READ_ERROR;

    return boost::make_shared<ClRandomFloatArrayGenerator>(arraySize);
}

boost::shared_ptr<IClDataGenerator> ClDataGeneratorFromFileReader::readComposizeOfGenerators(FILE* file)
{
    uint compositesCount;
    size_t readBytes = fread( &compositesCount, sizeof(uint), 1, file);
    if ( readBytes < 1 ) 
        throw FILE_READ_ERROR;

    std::vector<boost::shared_ptr<IClDataGenerator> > composites;
    for (uint i=0; i<compositesCount; ++i) 
    {
        composites.push_back( read(file));
    }

    return boost::make_shared<ClDataGeneratorComposite>(composites);
}

