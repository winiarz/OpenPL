#include "seLocalMatrix4x4.hpp"
using namespace OPL::SimExec;

LocalMatrix4x4::LocalMatrix4x4() {}

LocalMatrix4x4::LocalMatrix4x4(float a00,float a01,float a02,float a03,float a10,float a11,float a12,float a13,float a20,float a21,float a22,float a23,float a30,float a31,float a32,float a33)
{
  values[0][0] = a00; values[0][1] = a01; values[0][2] = a02; values[0][3] = a03;
  values[1][0] = a10; values[1][1] = a11; values[1][2] = a12; values[1][3] = a13;
  values[2][0] = a20; values[2][1] = a21; values[2][2] = a22; values[2][3] = a23;
  values[3][0] = a30; values[3][1] = a31; values[3][2] = a32; values[3][3] = a33;
}

LocalMatrix4x4 LocalMatrix4x4::operator+(LocalMatrix4x4 second)
{
  LocalMatrix4x4 result;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      result.values[i][j] = values[i][j] + second.values[i][j];
  return result;
}

LocalMatrix4x4 LocalMatrix4x4::operator*(LocalMatrix4x4 second)
{
  LocalMatrix4x4 result;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
      result.values[i][j] = 0;
      for(int k=0;k<4;k++)
	result.values[i][j] += values[i][k]*second.values[k][j];
    }
  return result;
}

LocalMatrix4x4 OPL::SimExec::operator*(float scalar,LocalMatrix4x4 matrix)
{
  LocalMatrix4x4 result;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      result.values[i][j] = scalar * matrix.values[i][j];
  return result;
}

bool LocalMatrix4x4::operator==(LocalMatrix4x4 second)
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      if( values[i][j] != second.values[i][j])
	return false;
  return true;
}
