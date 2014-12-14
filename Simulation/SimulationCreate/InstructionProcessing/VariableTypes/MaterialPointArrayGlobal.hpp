#pragma once
#include "GlobalArrayVariableWithSize.hpp"
#include "MaterialPoint.hpp"

namespace InsPr
{
    class MaterialPointArrayGlobal : public GlobalArrayVariableWithSize<MaterialPoint>
    {
    public:
        void move();
        void setForce(Float4);
    };
}

