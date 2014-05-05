#ifndef __OPL_SC_MATERIALPOINT__
#define __OPL_SC_MATERIALPOINT__
#include "scTypes.hpp"
#include "scVariable.hpp"
namespace OPL
{
  namespace SimCreate
  {
    class MaterialPoint : public Variable {
    public:
      Float3 position;
      Float3 speed;
      Float3 force;
      Float mass;
      FloatArray nothing;
      MaterialPoint(string);
      MaterialPoint operator=(MaterialPoint);
      static string getTypeName();
      MaterialPoint operator<<(Float3);
    };
  }
}
#endif
