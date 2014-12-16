#pragma once
#include "GlobalArrayVariableWithSize.hpp"
#include "MaterialPoint.hpp"

namespace InsPr
{
    class MaterialPointArrayGlobal : public GlobalArrayVariableWithSize<MaterialPoint>
    {
    public:
        void clearForce();
        void move();
        void setForce(Float4);
        void applyForcesOfGravity(Float);
    };
}

