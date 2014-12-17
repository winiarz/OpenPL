#pragma once

#include "IClSelfCalibratingKernelFromFileReader.hpp"
#include "IClDataGeneratorFromFileReader.hpp"
#include "ClKernelFromBinaryLoader.hpp"
#include "IClock.hpp"

namespace OPL
{

class ClSelfCalibratingKernelFromFileReader : public IClSelfCalibratingKernelFromFileReader
{
public:
    ClSelfCalibratingKernelFromFileReader( shared_ptr<IClDataGeneratorFromFileReader>,
                                           shared_ptr<ClKernelFromBinaryLoader>,
                                           IClock& );
    virtual shared_ptr<ClSelfCalibratingKernel> read(std::string filename);

private:
    shared_ptr<IClDataGeneratorFromFileReader> dataGeneratorReader;
    shared_ptr<ClKernelFromBinaryLoader> kernelLoader;
    IClock& clock;
};

}

