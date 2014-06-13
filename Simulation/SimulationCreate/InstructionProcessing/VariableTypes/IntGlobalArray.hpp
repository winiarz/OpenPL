#pragma once

#include "Int.hpp"
#include "Variable.hpp"

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

