#ifndef __OPL_SE_MATRIX_3X3__
#define __OPL_SE_MATRIX_3X3__

namespace OPL
{
  namespace SimExec
  {
    class LocalMatrix3x3 {
    public:
      LocalMatrix3x3();
      LocalMatrix3x3(float,float,float,float,float,float,float,float,float);
      bool operator==(LocalMatrix3x3);
      LocalMatrix3x3 operator+(LocalMatrix3x3);
      LocalMatrix3x3 operator*(LocalMatrix3x3);
  // private:
      float values[4][4];
      
      friend LocalMatrix3x3 operator*(float,LocalMatrix3x3);
    };
    
    LocalMatrix3x3 operator*(float,LocalMatrix3x3);
  }
}

#endif
