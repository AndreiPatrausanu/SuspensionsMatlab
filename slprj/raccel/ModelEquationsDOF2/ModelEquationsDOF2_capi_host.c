#include "ModelEquationsDOF2_capi_host.h"
static ModelEquationsDOF2_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        ModelEquationsDOF2_host_InitializeDataMapInfo(&(root), "ModelEquationsDOF2");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
