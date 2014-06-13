#include "VectorVariable.hpp"

namespace InsPr
{

uint getVectorVariableSize(VectorVariableSize size)
{
    switch ( size ) 
    {
    case VECTOR_VARIABLE_SIZE_2:
        return 2u;
    case VECTOR_VARIABLE_SIZE_4:
        return 4u;
    }
    return 0;
}

}

