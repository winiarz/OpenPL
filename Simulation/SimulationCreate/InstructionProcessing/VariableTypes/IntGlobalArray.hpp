#pragma once

#include "Int.hpp"
#include "Float.hpp"
#include "Variable.hpp"
#include "VectorVariable.hpp"
#include "MatrixVariable.hpp"
#include "MaterialPoint.hpp"

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

    typedef GlobalArrayVariable<MatrixFloat3x3> MatrixFloat3x3ArrayGlobal;
    typedef GlobalArrayVariable<MatrixFloat4x4> MatrixFloat4x4ArrayGlobal;

    typedef GlobalArrayVariable<MaterialPoint> MaterialPointArrayGlobal;
}

