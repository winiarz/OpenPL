#pragma once

#include "IClSelfCalibratingKernelFromFileReader.hpp"
#include "IClDataGeneratorFromFileReader.hpp"
#include "ClKernelFromBinaryLoader.hpp"
#include "IClock.hpp"

class ClSelfCalibratingKernelFromFileReader : public IClSelfCalibratingKernelFromFileReader
{
public:
    ClSelfCalibratingKernelFromFileReader( shared_ptr<OPL::IClDataGeneratorFromFileReader>,
                                           shared_ptr<OPL::ClKernelFromBinaryLoader>,
                                           IClock& );
    virtual shared_ptr<OPL::ClSelfCalibratingKernel> read(std::string filename);

private:
    shared_ptr<OPL::IClDataGeneratorFromFileReader> dataGeneratorReader;
    shared_ptr<OPL::ClKernelFromBinaryLoader> kernelLoader;
    IClock& clock;
};

