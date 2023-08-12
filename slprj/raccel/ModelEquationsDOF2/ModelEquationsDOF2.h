#ifndef RTW_HEADER_ModelEquationsDOF2_h_
#define RTW_HEADER_ModelEquationsDOF2_h_
#ifndef ModelEquationsDOF2_COMMON_INCLUDES_
#define ModelEquationsDOF2_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "ModelEquationsDOF2_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME ModelEquationsDOF2
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (3)     
#define NBLOCKIO (9) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (4)   
#elif NCSTATES != 4
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T daw4mlgab4 ; real_T hkc51o1r3j ; real_T myws1id50y ;
real_T g4yr0vtwax ; real_T ocia3xjh5x ; real_T dtyrmwdlrl ; real_T g0ldcin0om
; real_T eczoaexinb ; real_T cim5aoljt4 ; } B ; typedef struct { real_T
cfixiwqkrp ; real_T du12egghrd ; real_T ekrxxg0erb ; real_T piennvgrqo ;
struct { void * LoggedData ; } hmomj45t1n ; struct { void * LoggedData ; }
oovxadpc0d ; struct { void * LoggedData ; } g4zx5xiagr ; struct { void *
LoggedData ; } pbujuglgqm ; struct { void * LoggedData ; } csq4l1kzu5 ;
struct { void * LoggedData ; } euzykhloc1 ; struct { void * AQHandles ; }
l4hk4ayfzr ; struct { void * AQHandles ; } nqfjjqfmpd ; struct { void *
AQHandles ; } dkvh2msww4 ; struct { void * LoggedData ; } mmsop3jlex ; struct
{ void * AQHandles ; } fmslhtsxbv ; struct { void * AQHandles ; } gqhh5yhvhz
; struct { void * AQHandles ; } erzoh5yp2e ; struct { void * AQHandles ; }
bo14fpjqv4 ; } DW ; typedef struct { real_T oiut1i5lm5 ; real_T e422fmwxvg ;
real_T gndnjdd0up ; real_T oksa0vt5t1 ; } X ; typedef struct { real_T
oiut1i5lm5 ; real_T e422fmwxvg ; real_T gndnjdd0up ; real_T oksa0vt5t1 ; }
XDot ; typedef struct { boolean_T oiut1i5lm5 ; boolean_T e422fmwxvg ;
boolean_T gndnjdd0up ; boolean_T oksa0vt5t1 ; } XDis ; typedef struct {
real_T p5l14loct1 ; real_T elahtxe02w ; real_T lb1ncf1g1s ; } ExtY ; typedef
struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T cs
; real_T cu ; real_T ks ; real_T ku ; real_T ms ; real_T mu ; real_T
road_front_wheel [ 100 ] ; real_T Xs_DOT_IC ; real_T Xu_DOT_IC ; real_T
Xs_DOT_DOT_IC ; real_T Xu_DOT_DOT_IC ; real_T uDLookupTable_bp01Data [ 100 ]
; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern
X rtX ; extern DW rtDW ; extern ExtY rtY ; extern P rtP ; extern mxArray *
mr_ModelEquationsDOF2_GetDWork ( ) ; extern void
mr_ModelEquationsDOF2_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_ModelEquationsDOF2_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * ModelEquationsDOF2_GetCAPIStaticMap ( void )
; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
