#pragma once

#include "stl.hpp"
#include "boost.hpp"
#include "IVariable.hpp"
#include "Int.hpp"

namespace InsPr
{
    template<class T>
    class GlobalArrayVariable : public IGlobalArrayVariable
    {
    public:
        static_assert(std::is_base_of<IVariable, T>(), "T must be IVariable!");

        GlobalArrayVariable(boost::shared_ptr<IInstructionRecorder> recorder,
                            std::string p_name ) :
            IGlobalArrayVariable(recorder),
            name(p_name)
        {}

        virtual std::string getName()
        {
            return name;
        }

        virtual std::string getTypeName()
        {
            std::ostringstream sstream;
            sstream << "__global " << T(recorder,std::string("")).getTypeName() << "*";
            return sstream.str();
        }

        T operator[](Int nb)
        {
            std::ostringstream sstream;
            sstream << name << "[" << nb.getName() << "]";
            return T( recorder, sstream.str() );
        }
    private:
        std::string name;
    };
}

