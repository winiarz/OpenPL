#pragma once

#include "IClSelfCalibratingKernelFromFileReader.hpp"
#include "IClDataGeneratorFromFileReader.hpp"
#include "ClKernelFromBinaryLoader.hpp"
#include "IClock.hpp"

class ClSelfCalibratingKernelFromFileReader : public IClSelfCalibratingKernelFromFileReader
{
public:
    ClSelfCalibratingKernelFromFileReader( boost::shared_ptr<IClDataGeneratorFromFileReader>,
                                           boost::shared_ptr<ClKernelFromBinaryLoader>,
                                           IClock& );
    virtual boost::shared_ptr<ClSelfCalibratingKernel> read(std::string filename);

private:
    boost::shared_ptr<IClDataGeneratorFromFileReader> dataGeneratorReader;
		boost::shared_ptr<ClKernelFromBinaryLoader> kernelLoader;
		IClock& clock;
};

