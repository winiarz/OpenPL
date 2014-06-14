#include "InstructionRecorder.hpp"
#include "ForLoop.hpp"
#include "WhileLoop.hpp"
#include "IfInstruction.hpp"

namespace InsPr
{
InstructionRecorder::InstructionRecorder() :
    instructionBlocks(),
    includes()
{
    startBlock();
}

void InstructionRecorder::operator<<(boost::shared_ptr<IInstruction> instruction)
{
    if ( shouldCloseBlock ) 
        closeBlock();
    instructionBlocks.top()->addInstruction(instruction);
}

void InstructionRecorder::startBlock()
{
    if ( shouldCloseBlock ) 
        closeBlock();
    instructionBlocks.push(boost::make_shared<InstructionBlock>());
}

void InstructionRecorder::finishBlock()
{
    shouldCloseBlock = true;
}

void InstructionRecorder::closeBlock()
{
    boost::shared_ptr<IInstructionBlock> topBlock = instructionBlocks.top();
    instructionBlocks.pop();
    instructionBlocks.top()->addInstruction(topBlock);
    shouldCloseBlock = false;
}

void InstructionRecorder::finishAllBlocks()
{
    while (instructionBlocks.size() > 1) 
    {
        closeBlock();
    }
}

boost::shared_ptr<IInstructionBlock> InstructionRecorder::getBlock()
{
    finishAllBlocks();
    boost::shared_ptr<IInstructionBlock> result = instructionBlocks.top();
    instructionBlocks = std::stack<boost::shared_ptr<IInstructionBlock>>();
    startBlock();
    return result;
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
    shouldCloseBlock = false;
    instructionBlocks.top()->startElse();
}

void InstructionRecorder::addInclude(std::string p_include)
{
    includes.push_back( p_include );
}

std::vector<std::string> InstructionRecorder::getIncludes()
{
    std::vector<std::string> result = includes;
    includes.clear();\
    return result;
}

}

