#pragma once

#include "ClArrayMemory.hpp"
#include "seLocalMaterialPoint.hpp"

namespace OPL
{

class ClMemoryMaterialPointSOAWithSize : public IClMemory
{
public:
    ClMemoryMaterialPointSOAWithSize(uint);

    virtual bool isSetUpSuccessfully() override;
    virtual void copyIn (void*,uint,uint) override;
    virtual void copyOut(void*,uint,uint) override;
    virtual uint getSize() override;
    virtual std::vector<cl_mem> getMemories() override;
private:
    void copyInPositions(SimExec::LocalMaterialPoint*, uint, uint);
    void copyInVelocities(SimExec::LocalMaterialPoint*, uint, uint);
    void copyInForces(SimExec::LocalMaterialPoint*, uint, uint);
    void copyInMasses(SimExec::LocalMaterialPoint*, uint, uint);

    void copyOutPositions(SimExec::LocalMaterialPoint*, uint, uint);
    void copyOutVelocities(SimExec::LocalMaterialPoint*, uint, uint);
    void copyOutForces(SimExec::LocalMaterialPoint*, uint, uint);
    void copyOutMasses(SimExec::LocalMaterialPoint*, uint, uint);

    ClArrayMemory<float> positions;
    ClArrayMemory<float> velocities;
    ClArrayMemory<float> forces;
    ClArrayMemory<float> masses;
    ClArrayMemory<uint> size;
    uint localSize;
};

}

