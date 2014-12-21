#include <gtest/gtest.h>
#include "ClIncludeDirsParamReader.hpp"

namespace OPL
{

using namespace testing;
class ClIncludeDirsParamReaderTestSuite : public Test
{
public:
    ClIncludeDirsParamReaderTestSuite() :
        sut(fakeIncludeDirs)
    {
    }
protected:
    std::vector<std::string> fakeIncludeDirs;
    ClIncludeDirsParamReader sut;
};

TEST_F(ClIncludeDirsParamReaderTestSuite, shouldReturnProperParamName)
{
    ASSERT_EQ("ClIncludeDirs", sut.getName());
}

TEST_F(ClIncludeDirsParamReaderTestSuite, shouldClearParam_whenStreamIsEmpty)
{
    fakeIncludeDirs.push_back("exampleDir");
    std::stringstream emptyStream;
    sut.readParam(emptyStream);
    ASSERT_TRUE(fakeIncludeDirs.empty());
}

TEST_F(ClIncludeDirsParamReaderTestSuite, shouldAddDirsFromStread)
{
    fakeIncludeDirs.push_back("exampleDir");
    std::stringstream stream("dir1 dir2");
    sut.readParam(stream);
    ASSERT_EQ(2, fakeIncludeDirs.size());
    ASSERT_EQ("dir1", fakeIncludeDirs[0]);
    ASSERT_EQ("dir2", fakeIncludeDirs[1]);
}

}
