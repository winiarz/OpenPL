#include <stack>
#include "InstructionRecorder.hpp"
#include "ForLoop.hpp"
#include "WhileLoop.hpp"
#include "IfInstruction.hpp"

namespace OPL
{
namespace InsPr
{
using std::make_shared;

InstructionRecorder::InstructionRecorder() :
    instructionBlocks(),
    includes()
{
    startBlock();
}

void InstructionRecorder::operator<<(shared_ptr<IInstruction> instruction)
{
    if ( shouldCloseBlock ) 
        closeBlock();
    instructionBlocks.top()->addInstruction(instruction);
}

void InstructionRecorder::startBlock()
{
    if ( shouldCloseBlock ) 
        closeBlock();
    instructionBlocks.push(make_shared<InstructionBlock>());
}

void InstructionRecorder::finishBlock()
{
    shouldCloseBlock = true;
}

void InstructionRecorder::closeBlock()
{
    shared_ptr<IInstructionBlock> topBlock = instructionBlocks.top();
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

shared_ptr<IInstructionBlock> InstructionRecorder::getBlock()
{
    finishAllBlocks();
    shared_ptr<IInstructionBlock> result = instructionBlocks.top();
    instructionBlocks = std::stack<shared_ptr<IInstructionBlock>>();
    startBlock();
    return result;
}

void InstructionRecorder::startForLoop(shared_ptr<SingleInstruction> startInstruction,
                                       shared_ptr<SingleInstruction> continueCondition,
                                       shared_ptr<SingleInstruction> afterCircuitInstruction)
{
    instructionBlocks.push(make_shared<ForLoop>(startInstruction,
                                                       continueCondition,
                                                       afterCircuitInstruction) );
}

void InstructionRecorder::startWhileLoop(shared_ptr<SingleInstruction> condition)
{
    instructionBlocks.push(make_shared<WhileLoop>(condition) );
}

void InstructionRecorder::startIf(shared_ptr<SingleInstruction> condition)
{
    instructionBlocks.push(make_shared<IfInstruction>(condition) );
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
    includes.clear();
    return result;
}

}
}

