#include "NumericVariable.hpp"
#include "logs.hpp"

namespace InsPr
{

std::string getNumericTypeName(NumericVariableTypes type)
{
    switch (type) 
    {
    case VARIABLE_TYPE_INT:
        return "int";        
    case VARIABLE_TYPE_FLOAT:
        return "float";
    }
    ERROR << "variable type unknown " << int(type);
    return "ERROR - type unknown!";
}

}

