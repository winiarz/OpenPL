#pragma once

#include "scISimStep.hpp"
#include "IKernel.hpp"
#include "ClKernel.hpp"

namespace OPL
{
namespace SimCreate
{
    class SingleKernelSimStep : public ISimStep
    {
    public:
        SingleKernelSimStep(shared_ptr<InsPr::IKernel>);

        void execute(std::vector<shared_ptr<ClMemory>>);
        void execute(std::vector<ClMemory*>);
    private:
        shared_ptr<InsPr::IKernel> recordedKernel;
        shared_ptr<ClKernel> compiledKernel;

        void loadKernelIfNotLoaded();
    };
}
}

