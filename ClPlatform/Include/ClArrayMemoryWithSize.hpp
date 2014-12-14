#pragma once

#include "ClArrayMemory.hpp"

template<typename T>
class ClArrayMemoryWithSize : public IClMemory
{
public:
    ClArrayMemoryWithSize(uint n) :
        array(n),
        size(1)
    {
        size.copyIn(&n,0,1);
    }

    void copyIn (void* data, uint start, uint size)
    {
        array.copyIn((T*)data, start, size);
    }

    void copyOut(void* data, uint start, uint size)
    {
        array.copyOut((T*)data, start, size);
    }

    std::vector<cl_mem> getMemories()
    {
        return std::vector<cl_mem> {array.getMemories()[0], size.getMemories()[0]};
    }

    bool isSetUpSuccessfully()
    {
        return array.isSetUpSuccessfully() && size.isSetUpSuccessfully();
    }

    uint getSize()
    {
        return array.getSize() + size.getSize();
    }
private:
    ClArrayMemory<T> array;
    ClArrayMemory<uint> size;
};

