#include "MaterialPointArrayGlobal.hpp"

namespace InsPr
{

void MaterialPointArrayGlobal::move()
{
    InsPr::IVariable::recorder->addInclude("material_point_move.cl");
    std::ostringstream sstream;
    sstream << "material_point_move ( " << array.getName() << ",0, " << size.getName() << "[0],1 );\n";
    (*recorder) << make_shared<InsPr::SingleInstruction>(sstream.str());
}

}

