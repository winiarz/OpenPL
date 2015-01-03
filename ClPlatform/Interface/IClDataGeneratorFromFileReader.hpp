#pragma once
#include <memory>
using std::shared_ptr;

namespace OPL
{
class IClDataGenerator;

class IClDataGeneratorFromFileReader
{
public:
    virtual std::shared_ptr<IClDataGenerator> read(FILE*) = 0;
};

}

