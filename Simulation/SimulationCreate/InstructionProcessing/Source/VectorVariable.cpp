#include "VectorVariable.hpp"

namespace OPL
{
namespace InsPr
{

uint getVectorVariableSize(VectorVariableSize size)
{
    switch ( size ) 
    {
    case VECTOR_VARIABLE_SIZE_2:
        return 2u;
    case VECTOR_VARIABLE_SIZE_3:
        return 3u;
    case VECTOR_VARIABLE_SIZE_4:
        return 4u;
    }
    return 0;
}

VectorVariable<VARIABLE_TYPE_FLOAT,VECTOR_VARIABLE_SIZE_3> // TODO: make it a template
    operator^ (VectorVariable<VARIABLE_TYPE_FLOAT,VECTOR_VARIABLE_SIZE_3> first,
               VectorVariable<VARIABLE_TYPE_FLOAT,VECTOR_VARIABLE_SIZE_3> second)
{
    IVariable::recorder->addInclude("crossOperation.cl");
    std::ostringstream sstream;
    sstream << " floatCrossProduct( " << first.getName() << ", " << second.getName() << ") ";
    return VectorVariable<VARIABLE_TYPE_FLOAT,VECTOR_VARIABLE_SIZE_3>( sstream.str());
}

}
}

