#pragma once

#include "IVariable.hpp"

namespace InsPr
{
    class NumericVariable : public IVariable
    {
    public:
        NumericVariable(boost::shared_ptr<IInstructionRecorder> recorder) :
            IVariable(recorder)
        {}

        NumericVariable(VariableCreateType type,
                        boost::shared_ptr<IInstructionRecorder> p_recorder = boost::shared_ptr<IInstructionRecorder>() ) :
            IVariable(type, p_recorder)
        {}

        virtual std::string getName() = 0;
        virtual std::string getTypeName() = 0;
    };

    template<class T>
    T operator+(T& first, T& second)
    {
        static_assert(std::is_base_of<NumericVariable, T>(), "T must be NumericVariable!");
        std::ostringstream sstream;
        sstream << first.getName() << " + " << second.getName();
        return T(first.recorder, sstream.str());
    }

    template<class T>
    T operator-(T& first, T& second)
    {
        static_assert(std::is_base_of<NumericVariable, T>(), "T must be NumericVariable!");
        std::ostringstream sstream;
        sstream << first.getName() << " - " << second.getName();
        return T(first.recorder, sstream.str());
    }

    template<class T>
    T operator*(T& first, T& second)
    {
        static_assert(std::is_base_of<NumericVariable, T>(), "T must be NumericVariable!");
        std::ostringstream sstream;
        sstream << first.getName() << " * " << second.getName();
        return T(first.recorder, sstream.str());
    }

    template<class T>
    T operator/(T& first, T& second)
    {
        static_assert(std::is_base_of<NumericVariable, T>(), "T must be NumericVariable!");
        std::ostringstream sstream;
        sstream << first.getName() << " / " << second.getName();
        return T(first.recorder, sstream.str());
    }
}

