#include "ClRandomFloatArrayGenerator.hpp"
#include "ClTypedMemory.hpp"
#include <cstdlib>

ClRandomFloatArrayGenerator::ClRandomFloatArrayGenerator(uint p_arraySize) :
    arraySize(p_arraySize)
{
}

vector<boost::shared_ptr<ClMemory> > ClRandomFloatArrayGenerator::getData()
{
    srand48( time(NULL));
    float generatedArray[arraySize];

    for (uint i=0; i<arraySize; i++) 
        generatedArray[i] = drand48();

    boost::shared_ptr<ClTypedMemory<float> > memory = boost::make_shared<ClTypedMemory<float> >(arraySize);

    memory->copyIn(generatedArray, 0, arraySize);

    std::vector<boost::shared_ptr<ClMemory> > result;
    result.push_back( memory );
    return result;
}

