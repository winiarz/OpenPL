#include "ClKernelManager.hpp"
#include "IClKernelCallStats.hpp"
#include "ClKernel.hpp"

void ClKernelManager::loadKernel( ClKernel* kernel)
{
    bool isPossibleToLoad = true;

    while ( isPossibleToLoad ) 
    {
        try
        {
            kernel->load();
            loadedKernels.insert(kernel);
            return;
        }
        catch ( ClError error ) 
        {
            if ( error == OUT_OF_RESOURCES ) 
            {
                unloadOneKernel(isPossibleToLoad);
            }
        }
    }
}

void ClKernelManager::unloadOneKernel(bool& isPossibleToLoad)
{
    float worstScore = std::numeric_limits<float>::max();
    KernelPtrSet::iterator kernelToUnload = loadedKernels.end();
    
    if ( loadedKernels.empty() ) 
    {
        isPossibleToLoad = false;
        return;
    }
    for (KernelPtrSet::iterator i = loadedKernels.begin(); i!= loadedKernels.end(); ++i) 
    {
        float score = (*i)->getStats().getScore();
        if ( score < worstScore ) 
        {
            worstScore = score;
        }
    }

    if ( kernelToUnload != loadedKernels.end() ) 
    {
        (*kernelToUnload)->unload();
        loadedKernels.erase(kernelToUnload);
    }
    else
        isPossibleToLoad = false;
}

ClKernelManager::~ClKernelManager()
{
}

