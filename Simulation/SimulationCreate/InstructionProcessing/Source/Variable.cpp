#include "Variable.hpp"

namespace InsPr
{

Variable::Variable(boost::shared_ptr<IType> p_type,
                   std::string p_name) :
    type(p_type),
    name(p_name)
{
}

boost::shared_ptr<IType> Variable::getType()
{
    return type;
}

std::string Variable::getName()
{
    return name;
}

}

