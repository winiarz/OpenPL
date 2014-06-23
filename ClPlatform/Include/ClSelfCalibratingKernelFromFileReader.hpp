#pragma once

#include "IClSelfCalibratingKernelFromFileReader.hpp"
#include "IClDataGeneratorFromFileReader.hpp"
#include "ClKernelFromBinaryLoader.hpp"
#include "IClock.hpp"

class ClSelfCalibratingKernelFromFileReader : public IClSelfCalibratingKernelFromFileReader
{
public:
    ClSelfCalibratingKernelFromFileReader( std::shared_ptr<IClDataGeneratorFromFileReader>,
                                           std::shared_ptr<ClKernelFromBinaryLoader>,
                                           IClock& );
    virtual boost::shared_ptr<ClSelfCalibratingKernel> read(std::string filename);

private:
    std::shared_ptr<IClDataGeneratorFromFileReader> dataGeneratorReader;
    std::shared_ptr<ClKernelFromBinaryLoader> kernelLoader;
    IClock& clock;
};

