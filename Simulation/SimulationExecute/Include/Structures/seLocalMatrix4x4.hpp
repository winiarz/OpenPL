#ifndef __OPL_SE_MATRIX_4X4__
#define __OPL_SE_MATRIX_4X4__

namespace OPL
{
  namespace SimExec
  {
    class LocalMatrix4x4 {
    public:
      LocalMatrix4x4();
      LocalMatrix4x4(float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float);
      bool operator==(LocalMatrix4x4);
      LocalMatrix4x4 operator+(LocalMatrix4x4);
      LocalMatrix4x4 operator*(LocalMatrix4x4);
    private:
      float values[4][4];
      
      friend LocalMatrix4x4 operator*(float,LocalMatrix4x4);
    };
    
    LocalMatrix4x4 operator*(float,LocalMatrix4x4);
  }
}

#endif
