#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "KernelLoader.hpp"
#include "ClKernelFactoryMock.hpp"
#include "ClKernelMock.hpp"

using namespace ::testing;

class KernelLoaderTestSuite : public Test {
protected:
  KernelLoader* sut;
  StrictMock<ClKernelFactoryMock>* kernelFactoryMock;
  
  std::string fileName;
  std::string kernelName;
  
  IClKernel* loadKernelSuccessfully(StrictMock<ClKernelMock>* kernelMock)
  {
    EXPECT_CALL( *kernelFactoryMock, buildClKernel(fileName,kernelName) ).WillOnce(Return(kernelMock));
    EXPECT_CALL( *kernelMock, isLoaded() ).Times(AtLeast(1)).WillRepeatedly(Return(true));
    
    IClKernel* kernel = sut->load( fileName, kernelName);
    return kernel;
  }
  
  void deleteKernel(StrictMock<ClKernelMock>* kernel)
  {
    EXPECT_CALL( *kernel, Die() );
    delete kernel;
  }
public:
  KernelLoaderTestSuite() : 
	    fileName("exampleFile.clbin"),
	    kernelName("exampleKernel")
  {
    kernelFactoryMock = new StrictMock<ClKernelFactoryMock>;
    
    sut = new KernelLoader(kernelFactoryMock);
  }
  ~KernelLoaderTestSuite()
  {
    delete kernelFactoryMock;
  }
};

TEST_F( KernelLoaderTestSuite, autoUnloadisDisabledByDefault )
{
  ASSERT_EQ( sut->isAutoUnloadEnabled(), false );
}

TEST_F( KernelLoaderTestSuite, afterEnabling_AutoUnloadIsEnabled )
{
  sut->enableAutoUnload();
  ASSERT_EQ( sut->isAutoUnloadEnabled(), true );
}

TEST_F( KernelLoaderTestSuite, loadSingleKernel )
{ 
  StrictMock<ClKernelMock>* kernelMock = new StrictMock<ClKernelMock>;
  
  IClKernel* kernel = loadKernelSuccessfully(kernelMock);
  ASSERT_TRUE( kernel != NULL );
  
  deleteKernel( kernelMock);
}

TEST_F( KernelLoaderTestSuite, kernelLoadFail )
{
  StrictMock<ClKernelMock>* kernelMock = new StrictMock<ClKernelMock>;
  
  EXPECT_CALL( *kernelFactoryMock, buildClKernel(fileName,kernelName) ).WillOnce(Return(kernelMock));
  EXPECT_CALL( *kernelMock, isLoaded() ).Times(AtLeast(1)).WillRepeatedly(Return(false));
  EXPECT_CALL( *kernelMock, Die() );
  
  IClKernel* kernel = sut->load( fileName, kernelName);
  ASSERT_TRUE( kernel == NULL );
}

TEST_F( KernelLoaderTestSuite, loadMultipleKernels )
{
  const int kernelCount=5;
  
  for(int i=0;i<kernelCount;i++)
  {
    StrictMock<ClKernelMock>* kernelMock = new StrictMock<ClKernelMock>;
    IClKernel* kernel = loadKernelSuccessfully(kernelMock);
    ASSERT_TRUE( kernel != NULL );
    
    deleteKernel( kernelMock);
  }
}

TEST_F( KernelLoaderTestSuite, autopUnloadEnabled_deleteOldKernelWhenOutOfResources )
{
    sut->enableAutoUnload();
    StrictMock<ClKernelMock>* oldKernel = new StrictMock<ClKernelMock>;
    loadKernelSuccessfully(oldKernel);

    StrictMock<ClKernelMock>* badKernel = new StrictMock<ClKernelMock>;
    StrictMock<ClKernelMock>* goodKernel = new StrictMock<ClKernelMock>;
  
    EXPECT_CALL( *kernelFactoryMock, buildClKernel(fileName,kernelName) ).WillOnce( DoAll ( Throw(OUT_OF_RESOURCES),
                                                                                          Return(badKernel) ))
                                                                       .WillOnce( Return(goodKernel) );
    EXPECT_CALL( *badKernel, isLoaded() ).WillRepeatedly(Return(false));
    EXPECT_CALL( *oldKernel, Die() );
    EXPECT_CALL( *badKernel, Die() );
    EXPECT_CALL( *goodKernel, isLoaded() ).Times(AtLeast(1)).WillRepeatedly(Return(true));

    IClKernel* kernel2 = sut->load( fileName, kernelName);
    ASSERT_TRUE( kernel2 != NULL );

    deleteKernel( goodKernel );
    delete badKernel;
}

TEST_F( KernelLoaderTestSuite, autoUnloadDisabled_notToAutoDeleteOldKernels )
{
    StrictMock<ClKernelMock>* oldKernel = new StrictMock<ClKernelMock>;
    loadKernelSuccessfully(oldKernel);

    StrictMock<ClKernelMock>* badKernel = new StrictMock<ClKernelMock>;

    EXPECT_CALL( *kernelFactoryMock, buildClKernel(fileName,kernelName) ).WillOnce( DoAll ( Throw(OUT_OF_RESOURCES),
                                                                                          Return(badKernel) ));
    EXPECT_CALL( *badKernel, isLoaded() ).WillRepeatedly(Return(false));
    EXPECT_CALL( *badKernel, Die() );

    IClKernel* kernel2 = sut->load( fileName, kernelName);
    ASSERT_TRUE( kernel2 == NULL );

    deleteKernel( oldKernel );
    delete badKernel;
}
