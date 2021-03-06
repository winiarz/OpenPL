#include "ClSelfCalibratingKernelFromFileReader.hpp"
#include "ClSelfCalibratingKernel.hpp"
#include "ClKernelPerformanceComparator.hpp"
#include "ClKernel.hpp"
#include "ClError.hpp"
#include "logs.hpp"
#include <cstdio>

namespace OPL
{

ClSelfCalibratingKernelFromFileReader::ClSelfCalibratingKernelFromFileReader( shared_ptr<IClDataGeneratorFromFileReader> p_dataGeneratorReader,
                                                                              shared_ptr<ClKernelFromBinaryLoader> p_kernelLoader,
																			  IClock& p_clock ) :
    dataGeneratorReader( p_dataGeneratorReader ),
    kernelLoader( p_kernelLoader ),
    clock( p_clock )
{
}

shared_ptr<ClSelfCalibratingKernel> ClSelfCalibratingKernelFromFileReader::read(std::string filename)
{
    FILE* file = fopen( filename.c_str(), "rb" );
		if( file == NULL )
		    throw FILE_READ_ERROR;
    
		char prefix;
		size_t readElems = fread( &prefix, sizeof(prefix), 1, file );
		if( readElems < 1 )
	      throw FILE_READ_ERROR;

    if( prefix != 'S' )
    {
        ERROR << "invalid prefix in self calibrating kernel file = " << prefix;
        throw INCORRECT_KERNEL_FILE;
    }

    shared_ptr<IClDataGenerator> dataGenerator = dataGeneratorReader->read( file );

    uint kernelsCount;
    readElems = fread( &kernelsCount, sizeof(kernelsCount), 1, file);
    if( readElems < 1 )
        throw FILE_READ_ERROR;

    auto performanceComparator = make_shared<ClKernelPerformanceComparator>(clock);

    performanceComparator->setDataGenerator( dataGenerator );

    for( uint i=0; i<kernelsCount; ++i )
    {
        performanceComparator->addKernel( kernelLoader->loadKernel(file) );	
    }

    return make_shared<ClSelfCalibratingKernel>( performanceComparator );
}

}

