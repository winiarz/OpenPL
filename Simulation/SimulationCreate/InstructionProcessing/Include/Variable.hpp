#pragma once

#include "IVariable.hpp"

namespace InsPr
{
    class Variable : public IVariable
    {
    public:
        Variable(boost::shared_ptr<IType>,
                 std::string);
        virtual boost::shared_ptr<IType> getType();
        virtual std::string getName();
    private:
        boost::shared_ptr<IType> type;
        std::string name;
    };
}

