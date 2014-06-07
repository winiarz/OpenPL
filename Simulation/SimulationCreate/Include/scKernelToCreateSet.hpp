#pragma once

#include <set>
#include "scCreateKernel.hpp"

namespace OPL
{
  namespace SimCreate
  {
    class KernelToCreateSet {
    public:
      void addKernel(CreateKernel*);
      void createAllKernels();
      void createFirstKernel();
      bool loadKernel(ClKernel**,std::string,std::string);
      void loadAndRunKernel0( ClKernel**, std::string, std::string );
      void loadAndRunKernel1( ClKernel**, std::string, std::string, ClMemory* );
      void loadAndRunKernel2( ClKernel**, std::string, std::string, ClMemory*, ClMemory* );
      
      static KernelToCreateSet& getKernelToCreateSet();
    private:
      std::set<CreateKernel*> kernelsSet;
    private:
      KernelToCreateSet();
      KernelToCreateSet(KernelToCreateSet&);
    };
  }
}

