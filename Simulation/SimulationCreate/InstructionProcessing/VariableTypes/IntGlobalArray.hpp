#pragma once

#include "Int.hpp"
#include "Float.hpp"
#include "Variable.hpp"
#include "VectorVariable.hpp"

namespace InsPr
{
    typedef GlobalArrayVariable<Int>  IntArrayGlobal;
    typedef GlobalArrayVariable<Int2> Int2ArrayGlobal;
    typedef GlobalArrayVariable<Int3> Int3ArrayGlobal;
    typedef GlobalArrayVariable<Int4> Int4ArrayGlobal;

    typedef GlobalArrayVariable<Float>   FloatArrayGlobal;
    typedef GlobalArrayVariable<Float2>  Float2ArrayGlobal;
    typedef GlobalArrayVariable<Float3>  Float3ArrayGlobal;
    typedef GlobalArrayVariable<Float4>  Float4ArrayGlobal;
}

