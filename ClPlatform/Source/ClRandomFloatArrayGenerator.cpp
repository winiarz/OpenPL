#include "ClRandomFloatArrayGenerator.hpp"
#include "ClTypedMemory.hpp"
#include <cstdlib>

ClRandomFloatArrayGenerator::ClRandomFloatArrayGenerator(uint p_arraySize) :
    arraySize(p_arraySize)
{
}

vector<shared_ptr<ClMemory> > ClRandomFloatArrayGenerator::getData()
{
    srand48( time(NULL));
    float generatedArray[arraySize];

    for (uint i=0; i<arraySize; i++) 
        generatedArray[i] = drand48();

    shared_ptr<ClTypedMemory<float> > memory = make_shared<ClTypedMemory<float> >(arraySize);

    memory->copyIn(generatedArray, 0, arraySize);

    std::vector<shared_ptr<ClMemory> > result;
    result.push_back( memory );
    return result;
}

void ClRandomFloatArrayGenerator::saveToFile( FILE* file)
{
    char prefix = 'F';

    size_t writtenBytes = fwrite( &prefix, sizeof(char), 1, file);
    if ( writtenBytes < 1 )
        throw FILE_WRITE_ERROR;

    writtenBytes = fwrite( &arraySize, sizeof(uint), 1, file);
    if ( writtenBytes < 1 )
        throw FILE_WRITE_ERROR;
}

