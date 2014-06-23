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
        SingleKernelSimStep(std::shared_ptr<InsPr::IKernel>);

        void execute(std::vector<std::shared_ptr<ClMemory>>);
        void execute(std::vector<ClMemory*>);
    private:
        std::shared_ptr<InsPr::IKernel> recordedKernel;
        std::shared_ptr<ClKernel> compiledKernel;

        void loadKernelIfNotLoaded();
    };
}
}

