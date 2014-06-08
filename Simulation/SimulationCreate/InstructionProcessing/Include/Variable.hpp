#pragma once

#include "stl.hpp"
#include "boost.hpp"
#include "IVariable.hpp"

namespace InsPr
{
    template<class T>
    class GlobalArrayVariable : public IGlobalArrayVariable
    {
    public:
        GlobalArrayVariable(boost::shared_ptr<IInstructionRecorder> recorder,
                            std::string p_name,
                            uint p_size = 0) :
            IGlobalArrayVariable(recorder),
            name(p_name),
            size(p_size)
        {}

        virtual std::string getName()
        {
            return name;
        }

        virtual std::string getTypeName()
        {
            std::ostringstream sstream;
            sstream << "__global " << T(recorder).getTypeName() << "*";
            return sstream.str();
        }
    private:
        std::string name;
        uint size;
    };
}

