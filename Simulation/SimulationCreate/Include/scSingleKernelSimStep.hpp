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
        SingleKernelSimStep(boost::shared_ptr<InsPr::IKernel>);

        void execute(std::vector<boost::shared_ptr<ClMemory>>);
        void execute(std::vector<ClMemory*>);
    private:
        boost::shared_ptr<InsPr::IKernel> recordedKernel;
        std::shared_ptr<ClKernel> compiledKernel;

        void loadKernelIfNotLoaded();
    };
}
}

