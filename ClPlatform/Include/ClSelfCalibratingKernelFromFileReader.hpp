#ifndef __CL_SELF_CALIBRATING_KERNEL_FROM_FILE_READER__
#define __CL_SELF_CALIBRATING_KERNEL_FROM_FILE_READER__

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

#endif
