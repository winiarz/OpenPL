#include "ClMemoryMaterialPointSOAWithSize.hpp"
#include "seLocalMaterialPoint.hpp"

namespace OPL
{

ClMemoryMaterialPointSOAWithSize::ClMemoryMaterialPointSOAWithSize(uint p_size) :
    positions(4*p_size),
    velocities(4*p_size),
    forces(4*p_size),
    masses(p_size),
    size(1),
    localSize(p_size)
{
    size.copyIn(&p_size,0,1);
}

bool ClMemoryMaterialPointSOAWithSize::isSetUpSuccessfully()
{
    return positions.isSetUpSuccessfully() &&
           velocities.isSetUpSuccessfully() &&
           forces.isSetUpSuccessfully() &&
           masses.isSetUpSuccessfully() &&
           size.isSetUpSuccessfully();
}

void ClMemoryMaterialPointSOAWithSize::copyIn (void* dataPtr,uint start,uint number)
{
    SimExec::LocalMaterialPoint* points = static_cast<SimExec::LocalMaterialPoint*>(dataPtr);
    copyInPositions(points, start, number);
    copyInVelocities(points, start, number);
    copyInForces(points, start, number);
    copyInMasses(points, start, number);
}

void ClMemoryMaterialPointSOAWithSize::copyOut(void* dataPtr, uint start, uint number)
{
    SimExec::LocalMaterialPoint* points = static_cast<SimExec::LocalMaterialPoint*>(dataPtr);
    copyOutPositions(points, start, number);
    copyOutVelocities(points, start, number);
    copyOutForces(points, start, number);
    copyOutMasses(points, start, number);
}

void ClMemoryMaterialPointSOAWithSize::copyInPositions(SimExec::LocalMaterialPoint* points, uint start, uint number)
{
    float locPositions[number*4];
    for (uint i=0;i<number;++i)
    {
        locPositions[4*i  ] = points[i].position[0];
        locPositions[4*i+1] = points[i].position[1];
        locPositions[4*i+2] = points[i].position[2];
    }
    positions.copyIn(locPositions, 4*start, 4*number);
}

void ClMemoryMaterialPointSOAWithSize::copyInVelocities(SimExec::LocalMaterialPoint* points, uint start, uint number)
{
    float locVelocities[number*4];
    for (uint i=0;i<number;++i)
    {
        locVelocities[4*i  ] = points[i].speed[0];
        locVelocities[4*i+1] = points[i].speed[1];
        locVelocities[4*i+2] = points[i].speed[2];
    }
    velocities.copyIn(locVelocities, 4*start, 4*number);
}

void ClMemoryMaterialPointSOAWithSize::copyInForces(SimExec::LocalMaterialPoint* points, uint start, uint number)
{
    float locForces[number*4];
    for (uint i=0;i<number;++i)
    {
        locForces[4*i  ] = points[i].force[0];
        locForces[4*i+1] = points[i].force[1];
        locForces[4*i+2] = points[i].force[2];
    }
    forces.copyIn(locForces, 4*start, 4*number);
}

void ClMemoryMaterialPointSOAWithSize::copyInMasses(SimExec::LocalMaterialPoint* points, uint start, uint number)
{
    float locMasses[number];
    for (uint i=0;i<number;++i)
    {
        locMasses[i] = points[i].mass;
    }
    masses.copyIn(locMasses, start, number);
}

void ClMemoryMaterialPointSOAWithSize::copyOutPositions(SimExec::LocalMaterialPoint* points, uint start, uint number)
{
    float locPositions[number*4];
    positions.copyOut(locPositions, 4*start, 4*number);
    for (uint i=0; i<number; ++i) 
    {
        points[i].position[0] = locPositions[4*i  ];
        points[i].position[1] = locPositions[4*i+1];
        points[i].position[2] = locPositions[4*i+2];
    }
}

void ClMemoryMaterialPointSOAWithSize::copyOutVelocities(SimExec::LocalMaterialPoint* points, uint start, uint number)
{
    float locVelocities[number*4];
    velocities.copyOut(locVelocities, 4*start, 4*number);
    for (uint i=0; i<number; ++i) 
    {
        points[i].speed[0] = locVelocities[4*i  ];
        points[i].speed[1] = locVelocities[4*i+1];
        points[i].speed[2] = locVelocities[4*i+2];
    }
}

void ClMemoryMaterialPointSOAWithSize::copyOutForces(SimExec::LocalMaterialPoint* points, uint start, uint number)
{
    float locForces[number*4];
    forces.copyOut(locForces, 4*start, 4*number);
    for (uint i=0; i<number; ++i) 
    {
        points[i].force[0] = locForces[4*i  ];
        points[i].force[1] = locForces[4*i+1];
        points[i].force[2] = locForces[4*i+2];
    }
}

void ClMemoryMaterialPointSOAWithSize::copyOutMasses(SimExec::LocalMaterialPoint* points, uint start, uint number)
{
    float locMasses[number];
    masses.copyOut(locMasses, start, number);
    for (uint i=0; i<number; ++i) 
    {
        points[i].mass = locMasses[i];
    }
}

uint ClMemoryMaterialPointSOAWithSize::getSize()
{
    return localSize;
}

std::vector<cl_mem> ClMemoryMaterialPointSOAWithSize::getMemories()
{
    return {};
}

}

