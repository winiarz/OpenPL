#pragma once

#include "scISimStep.hpp"
#include "IKernel.hpp"
#include "ClKernel.hpp"
#include "IOpenPlConfiguration.hpp"

namespace OPL
{
namespace SimCreate
{
    class SingleKernelSimStep : public ISimStep
    {
    public:
        SingleKernelSimStep(shared_ptr<InsPr::IKernel>,
                            IOpenPlConfiguration&);

        void execute(std::vector<shared_ptr<ClMemory>>);
        void execute(std::vector<ClMemory*>);
    private:
        shared_ptr<InsPr::IKernel> recordedKernel;
        shared_ptr<ClKernel> compiledKernel;
        IOpenPlConfiguration& openPlConfiguration;

        void loadKernelIfNotLoaded();
    };
}
}

