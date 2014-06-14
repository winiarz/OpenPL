#pragma once

#include "stl.hpp"
#include "boost.hpp"
#include "IVariable.hpp"
#include "Int.hpp"
#include "scNameGenerator.hpp"

namespace InsPr
{
    template<class T>
    class GlobalArrayVariable : public IGlobalArrayVariable
    {
    public:
        static_assert(std::is_base_of<IVariable, T>(), "T must be IVariable!");

        GlobalArrayVariable() :
            IGlobalArrayVariable(),
            name(OPL::SimCreate::NameGenerator::getNameGenerator().nextName())
        {}


        GlobalArrayVariable(std::string p_name ) :
            IGlobalArrayVariable(),
            name(p_name)
        {}

        virtual std::string getName()
        {
            return name;
        }

        virtual std::string getTypeName()
        {
            std::ostringstream sstream;
            sstream << "__global " << T(std::string("")).getTypeName() << "*";
            return sstream.str();
        }

        virtual std::vector<std::string> getRequiredIncludes()
        {
            return T("").getRequiredIncludes();
        }

        T operator[](Int nb)
        {
            std::ostringstream sstream;
            sstream << name << "[" << nb.getName() << "]";
            return T( sstream.str() );
        }
    private:
        std::string name;
    };
}

