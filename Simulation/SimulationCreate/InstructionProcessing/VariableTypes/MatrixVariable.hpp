#pragma once

#include "NumericVariable.hpp"
#include "Float.hpp"

namespace OPL
{
namespace InsPr
{

enum MatrixVariableSize
{
    MATRIX_VARIABLE_SIZE_3 = 3,
    MATRIX_VARIABLE_SIZE_4 = 4
};

uint getMatrixVariableSize(MatrixVariableSize size);

template<NumericVariableTypes type, MatrixVariableSize size>
class MatrixVariable : public NumericVariable
{
public:
    MatrixVariable() :
        NumericVariable(),
        name(OPL::SimCreate::NameGenerator::getNameGenerator().nextName())
    {
        recordDeclaration();
    }
        
    MatrixVariable(std::string p_name) :
        NumericVariable(),
        name(p_name)
    {}

    MatrixVariable( const MatrixVariable& original ) :
        NumericVariable(),
        name(original.name)
    {}

    virtual std::string getName()
    {
        return name;
    }

    virtual std::string getTypeName()
    {
        std::ostringstream sstream;
        sstream << "struct Matrix_" << getNumericTypeName(type) << "_" << getMatrixVariableSize(size) << "x" << getMatrixVariableSize(size);
        return sstream.str();
    }

    virtual std::vector<std::string> getRequiredIncludes()
    {
        std::vector<std::string> result;

        switch (size) 
        {
        case MATRIX_VARIABLE_SIZE_3:
            result.push_back("matrix_float_3x3.cl");
            break;
        case MATRIX_VARIABLE_SIZE_4:
            result.push_back("matrix_float_4x4.cl");
            break;
        }
        return result;
    }

    virtual Float det()
    {
        uint matrixSize = getMatrixVariableSize(size);
        ostringstream variableName;
        variableName << "matrix" << matrixSize << "x" << matrixSize << "_determinant(" << getName() << ") ";
        return Float(variableName.str());
    }

    MatrixVariable<type,size> invert()
    {
        uint matrixSize = getMatrixVariableSize(size);
        ostringstream variableName;
        variableName << "invertMatrix" << matrixSize << "x" << matrixSize << "(" << getName() << ") ";
        return MatrixVariable<type,size>(variableName.str());
    }
    
    MatrixVariable operator=( MatrixVariable rvalue )
    {
        recordAssigment(rvalue);
        return *this;
    }
private:
    std::string name;
};

template<NumericVariableTypes type, MatrixVariableSize size>
MatrixVariable<type,size> operator+( MatrixVariable<type,size> first, MatrixVariable<type,size> second )
{
    std::ostringstream sstream;
    sstream << "addMatrix ( " << first.getName() << " , " << second.getName() << " ) ";
    return MatrixVariable<type,size>( sstream.str());
}

template<NumericVariableTypes type, MatrixVariableSize size>
MatrixVariable<type,size> operator-( MatrixVariable<type,size> first, MatrixVariable<type,size> second )
{
    std::ostringstream sstream;
    sstream << "subMatrix ( " << first.getName() << " , " << second.getName() << " ) ";
    return MatrixVariable<type,size>( sstream.str());
}

template<NumericVariableTypes type, MatrixVariableSize size>
MatrixVariable<type,size> operator*( MatrixVariable<type,size> first, MatrixVariable<type,size> second )
{
    std::ostringstream sstream;
    sstream << "multMatrix ( " << first.getName() << " , " << second.getName() << " ) ";
    return MatrixVariable<type,size>( sstream.str());
}

template< MatrixVariableSize size>
MatrixVariable<VARIABLE_TYPE_FLOAT,size> operator*( MatrixVariable<VARIABLE_TYPE_FLOAT,size> first, Float second )
{
    uint matrixSize = getMatrixVariableSize(size);
    std::ostringstream sstream;
    sstream << "multMatrix" << matrixSize << "x" << matrixSize << "ByScalar ( " << first.getName() << " , " << second.getName() << " ) ";
    return MatrixVariable<VARIABLE_TYPE_FLOAT,size>( sstream.str());
}

template< MatrixVariableSize size>
MatrixVariable<VARIABLE_TYPE_FLOAT,size> operator*( Float first, MatrixVariable<VARIABLE_TYPE_FLOAT,size> second )
{
    uint matrixSize = getMatrixVariableSize(size);
    std::ostringstream sstream;
    sstream << "multScalarByMatrix" << matrixSize << "x" << matrixSize << " ( " << first.getName() << " , " << second.getName() << " ) ";
    return MatrixVariable<VARIABLE_TYPE_FLOAT,size>( sstream.str());
}

typedef MatrixVariable<VARIABLE_TYPE_FLOAT, MATRIX_VARIABLE_SIZE_3> MatrixFloat3x3;
typedef MatrixVariable<VARIABLE_TYPE_FLOAT, MATRIX_VARIABLE_SIZE_4> MatrixFloat4x4;

}
}

