#pragma once

#include "IVariable.hpp"
#include "scNameGenerator.hpp"

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

    enum NumericVariableTypes
    {
        VARIABLE_TYPE_INT
    };

    std::string getNumericTypeName(NumericVariableTypes type);

    template <NumericVariableTypes type>
    class TypedNumericVariable : public NumericVariable
    {
    public:
    TypedNumericVariable() :
        NumericVariable(CREATE_VARIABLE_WITH_LAST_RECORDER),
        name(OPL::SimCreate::NameGenerator::getNameGenerator().nextName())
    {}

    TypedNumericVariable(boost::shared_ptr<IInstructionRecorder> p_recorder,
        std::string p_name ) :
        NumericVariable(p_recorder),
        name(p_name)
    {}

    TypedNumericVariable(boost::shared_ptr<IInstructionRecorder> p_recorder) :
        NumericVariable(SET_LAST_RECORDER_ONLY, p_recorder)
    {}

    TypedNumericVariable( int constant ) :
        NumericVariable(boost::shared_ptr<IInstructionRecorder>())
    {
        std::ostringstream stringstream;
        stringstream << constant;
        name = stringstream.str();
    }
        
    TypedNumericVariable(std::string p_name) :
        NumericVariable(CREATE_VARIABLE_WITH_LAST_RECORDER),
        name(p_name)
    {}

    TypedNumericVariable( const TypedNumericVariable& original ) :
        NumericVariable(original.recorder),
        name(original.name)
    {}


    virtual std::string getName()
    {
        return name;
    }

    virtual std::string getTypeName()
    {
        return getNumericTypeName(type);
    }
    
    TypedNumericVariable operator=( TypedNumericVariable rvalue )
    {
        recordAssigment(rvalue);
        return *this;
    }
    private:
        std::string name;
    };



    template<class T>
    T operator+(T first, T second)
    {
        static_assert(std::is_base_of<NumericVariable, T>(), "T must be NumericVariable!");
        std::ostringstream sstream;
        sstream << first.getName() << " + " << second.getName();
        return T(first.recorder, sstream.str());
    }

    template<class T>
    T operator-(T first, T second)
    {
        static_assert(std::is_base_of<NumericVariable, T>(), "T must be NumericVariable!");
        std::ostringstream sstream;
        sstream << first.getName() << " - " << second.getName();
        return T(first.recorder, sstream.str());
    }

    template<class T>
    T operator*(T first, T second)
    {
        static_assert(std::is_base_of<NumericVariable, T>(), "T must be NumericVariable!");
        std::ostringstream sstream;
        sstream << first.getName() << " * " << second.getName();
        return T(first.recorder, sstream.str());
    }

    template<class T>
    T operator/(T first, T second)
    {
        static_assert(std::is_base_of<NumericVariable, T>(), "T must be NumericVariable!");
        std::ostringstream sstream;
        sstream << first.getName() << " / " << second.getName();
        return T(first.recorder, sstream.str());
    }
}

