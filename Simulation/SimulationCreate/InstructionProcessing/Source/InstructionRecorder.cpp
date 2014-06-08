#include "InstructionRecorder.hpp"
#include "ForLoop.hpp"
#include "WhileLoop.hpp"
#include "IfInstruction.hpp"

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

void InstructionRecorder::startForLoop(boost::shared_ptr<SingleInstruction> startInstruction,
                                       boost::shared_ptr<SingleInstruction> continueCondition,
                                       boost::shared_ptr<SingleInstruction> afterCircuitInstruction)
{
    instructionBlocks.push(boost::make_shared<ForLoop>(startInstruction,
                                                       continueCondition,
                                                       afterCircuitInstruction) );
}

void InstructionRecorder::startWhileLoop(boost::shared_ptr<SingleInstruction> condition)
{
    instructionBlocks.push(boost::make_shared<WhileLoop>(condition) );
}

void InstructionRecorder::startIf(boost::shared_ptr<SingleInstruction> condition)
{
    instructionBlocks.push(boost::make_shared<IfInstruction>(condition) );
}

void InstructionRecorder::startElse()
{
    instructionBlocks.top()->startElse();
}

}

