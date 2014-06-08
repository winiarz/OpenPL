#include "InstructionRecorder.hpp"

namespace InsPr
{
InstructionRecorder::InstructionRecorder() :
    instructionBlocks()
{
    startBlock();
}

void InstructionRecorder::operator<<(boost::shared_ptr<IInstruction> instruction)
{
    instructionBlocks.top()->addInstruction(instruction);
}

void InstructionRecorder::startBlock()
{
    instructionBlocks.push(boost::make_shared<InstructionBlock>());
}

void InstructionRecorder::finishBlock()
{
    boost::shared_ptr<IInstructionBlock> topBlock = instructionBlocks.top();
    instructionBlocks.pop();
    instructionBlocks.top()->addInstruction(topBlock);
}

void InstructionRecorder::finishAllBlocks()
{
    while (instructionBlocks.size() > 1) 
    {
        finishBlock();
    }
}

boost::shared_ptr<IInstructionBlock> InstructionRecorder::getBlock()
{
    finishAllBlocks();
    return instructionBlocks.top();
}

}

