#include "MatrixVariable.hpp"

namespace InsPr
{

uint getMatrixVariableSize(MatrixVariableSize size)
{
    switch (size) 
    {
    case MATRIX_VARIABLE_SIZE_3:
        return 3u;
    case MATRIX_VARIABLE_SIZE_4:
        return 4u;
    }
    return 0u;
}

}

