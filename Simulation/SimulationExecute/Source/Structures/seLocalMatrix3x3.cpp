#include <math.h>
#include "seLocalMatrix3x3.hpp"
using namespace OPL::SimExec;

LocalMatrix3x3::LocalMatrix3x3() {}

LocalMatrix3x3::LocalMatrix3x3(float a00,float a01,float a02,float a10,float a11,float a12,float a20,float a21,float a22)
{
  values[0][0] = a00; values[0][1] = a01; values[0][2] = a02;
  values[1][0] = a10; values[1][1] = a11; values[1][2] = a12;
  values[2][0] = a20; values[2][1] = a21; values[2][2] = a22;
}

LocalMatrix3x3 LocalMatrix3x3::operator+(LocalMatrix3x3 second)
{
  LocalMatrix3x3 result;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      result.values[i][j] = values[i][j] + second.values[i][j];
  return result;
}

LocalMatrix3x3 LocalMatrix3x3::operator*(LocalMatrix3x3 second)
{
  LocalMatrix3x3 result;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
      result.values[i][j] = 0;
      for(int k=0;k<3;k++)
	result.values[i][j] += values[i][k]*second.values[k][j];
    }
  return result;
}

LocalMatrix3x3 OPL::SimExec::operator*(float scalar,LocalMatrix3x3 matrix)
{
  LocalMatrix3x3 result;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      result.values[i][j] = scalar * matrix.values[i][j];
  return result;
}

bool LocalMatrix3x3::operator==(LocalMatrix3x3 second)
{
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      if( fabs( values[i][j] - second.values[i][j]) > 0.00001 )
	return false;
  return true;
}
