#include "ModelEquationsDOF2.h"
#include "mwmathutil.h"
#include "rtwtypes.h"
#include "ModelEquationsDOF2_private.h"
#include <string.h>
#include "rt_logging_mmi.h"
#include "ModelEquationsDOF2_capi.h"
#include "ModelEquationsDOF2_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "10.6 (R2022b) 13-May-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct
* S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; ExtY rtY ; static SimStruct model_S ; SimStruct *
const rtS = & model_S ; real_T look1_binlxpw ( real_T u0 , const real_T bp0 [
] , const real_T table [ ] , uint32_T maxIndex ) { real_T frac ; real_T
yL_0d0 ; uint32_T bpIdx ; uint32_T iLeft ; uint32_T iRght ; if ( u0 <= bp0 [
0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ]
) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = maxIndex >> 1U ; iLeft = 0U
; iRght = maxIndex ; while ( iRght - iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] )
{ iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U
; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ;
} else { iLeft = maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex - 1U ] ) / (
bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ; } yL_0d0 = table [ iLeft ] ;
return ( table [ iLeft + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } void
MdlInitialize ( void ) { rtX . oiut1i5lm5 = rtP . Xs_DOT_IC ; rtX .
e422fmwxvg = rtP . Xu_DOT_IC ; rtX . gndnjdd0up = rtP . Xs_DOT_DOT_IC ; rtX .
oksa0vt5t1 = rtP . Xu_DOT_DOT_IC ; rtDW . cfixiwqkrp = ( rtInf ) ; rtDW .
ekrxxg0erb = ( rtInf ) ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "Xb_DOT_DOT" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "Xb_DOT_DOT" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "ModelEquationsDOF2/Out1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Xb_DOT_DOT" )
; sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . l4hk4ayfzr . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "16fca3fa-4f19-4f7d-86d1-d1d7bb3a2fdd" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . l4hk4ayfzr . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . l4hk4ayfzr . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . l4hk4ayfzr . AQHandles , "0.001" ,
0.001 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . l4hk4ayfzr .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . l4hk4ayfzr . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
l4hk4ayfzr . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
l4hk4ayfzr . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . l4hk4ayfzr . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . l4hk4ayfzr . AQHandles , 3 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Xs" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "Xs" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"" ) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "ModelEquationsDOF2/Out6"
) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Xs" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. nqfjjqfmpd . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"e6db4cae-b2bf-4ff2-a467-903c1db8f457" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . nqfjjqfmpd . AQHandles , hDT , & srcInfo ) ; if ( rtDW . nqfjjqfmpd .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . nqfjjqfmpd . AQHandles ,
"0.001" , 0.001 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
nqfjjqfmpd . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . nqfjjqfmpd .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . nqfjjqfmpd . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . nqfjjqfmpd . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . nqfjjqfmpd . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . nqfjjqfmpd . AQHandles , 1 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Xu" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "Xu" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"" ) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "ModelEquationsDOF2/Out7"
) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Xu" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. dkvh2msww4 . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"659d78de-b1e7-4a6b-a22e-e3d66efec101" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . dkvh2msww4 . AQHandles , hDT , & srcInfo ) ; if ( rtDW . dkvh2msww4 .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . dkvh2msww4 . AQHandles ,
"0.001" , 0.001 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
dkvh2msww4 . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . dkvh2msww4 .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . dkvh2msww4 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . dkvh2msww4 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . dkvh2msww4 . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . dkvh2msww4 . AQHandles , 2 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Xs_DOT" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Xs_DOT" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "ModelEquationsDOF2/To Workspace" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Xs_DOT" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. fmslhtsxbv . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"76252f95-b368-4730-a45d-157cb471c28b" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . fmslhtsxbv . AQHandles , hDT , & srcInfo ) ; if ( rtDW . fmslhtsxbv .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . fmslhtsxbv . AQHandles ,
"0.001" , 0.001 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
fmslhtsxbv . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . fmslhtsxbv .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . fmslhtsxbv . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . fmslhtsxbv . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . fmslhtsxbv . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"Xb_ScopeData" ) ; sdiRegisterWksVariable ( rtDW . fmslhtsxbv . AQHandles ,
varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { {
bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Xs_DOT_DOT" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Xs_DOT_DOT" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "ModelEquationsDOF2/To Workspace1" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Xs_DOT_DOT" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. gqhh5yhvhz . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"0c923420-24d1-486a-b565-0ff9417f0575" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . gqhh5yhvhz . AQHandles , hDT , & srcInfo ) ; if ( rtDW . gqhh5yhvhz .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . gqhh5yhvhz . AQHandles ,
"0.001" , 0.001 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
gqhh5yhvhz . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . gqhh5yhvhz .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . gqhh5yhvhz . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . gqhh5yhvhz . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . gqhh5yhvhz . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"Xb_DOT_ScopeData" ) ; sdiRegisterWksVariable ( rtDW . gqhh5yhvhz . AQHandles
, varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { {
bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Gain16" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Gain16" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "ModelEquationsDOF2/To Workspace2" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Gain16" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. erzoh5yp2e . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"b8504601-be25-49a6-b216-ae015b79de26" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . erzoh5yp2e . AQHandles , hDT , & srcInfo ) ; if ( rtDW . erzoh5yp2e .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . erzoh5yp2e . AQHandles ,
"0.001" , 0.001 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
erzoh5yp2e . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . erzoh5yp2e .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . erzoh5yp2e . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . erzoh5yp2e . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . erzoh5yp2e . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"Xb_DOT_DOT_ScopeData" ) ; sdiRegisterWksVariable ( rtDW . erzoh5yp2e .
AQHandles , varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "Abs" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Abs" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"ModelEquationsDOF2/To Workspace3" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Abs" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . bo14fpjqv4 . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "e8a4f4cb-6d07-4768-8bec-56ec19b306dc" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . bo14fpjqv4 . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . bo14fpjqv4 . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . bo14fpjqv4 . AQHandles , "0.001" ,
0.001 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . bo14fpjqv4 .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . bo14fpjqv4 . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
bo14fpjqv4 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
bo14fpjqv4 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . bo14fpjqv4 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"SWS_ScopeData" ) ; sdiRegisterWksVariable ( rtDW . bo14fpjqv4 . AQHandles ,
varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } }
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T bufyw0qqkf ;
real_T cnxr3xxpnr ; real_T fayf3pksv5 ; real_T * lastU ; rtB . daw4mlgab4 =
rtX . oiut1i5lm5 ; rtY . p5l14loct1 = rtB . daw4mlgab4 ; rtB . hkc51o1r3j =
rtX . e422fmwxvg ; rtY . elahtxe02w = rtB . hkc51o1r3j ; rtB . myws1id50y =
rtX . gndnjdd0up ; rtB . g4yr0vtwax = rtX . oksa0vt5t1 ; fayf3pksv5 = ( rtB .
myws1id50y - rtB . g4yr0vtwax ) * rtP . cs ; bufyw0qqkf = ( rtB . daw4mlgab4
- rtB . hkc51o1r3j ) * rtP . ks ; rtB . ocia3xjh5x = ( ( 0.0 - fayf3pksv5 ) -
bufyw0qqkf ) * ( 1.0 / rtP . ms ) ; rtY . lb1ncf1g1s = rtB . ocia3xjh5x ; rtB
. dtyrmwdlrl = muDoubleScalarAbs ( rtB . daw4mlgab4 - rtB . hkc51o1r3j ) ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . g0ldcin0om = ssGetT ( rtS ) ; rtB
. eczoaexinb = look1_binlxpw ( rtB . g0ldcin0om , rtP .
uDLookupTable_bp01Data , rtP . road_front_wheel , 99U ) ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { { if ( rtDW . l4hk4ayfzr . AQHandles && ssGetLogOutput (
rtS ) ) { sdiWriteSignal ( rtDW . l4hk4ayfzr . AQHandles , ssGetTaskTime (
rtS , 1 ) , ( char * ) & rtB . ocia3xjh5x + 0 ) ; } } { if ( rtDW .
nqfjjqfmpd . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW .
nqfjjqfmpd . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB .
daw4mlgab4 + 0 ) ; } } { if ( rtDW . dkvh2msww4 . AQHandles && ssGetLogOutput
( rtS ) ) { sdiWriteSignal ( rtDW . dkvh2msww4 . AQHandles , ssGetTaskTime (
rtS , 1 ) , ( char * ) & rtB . hkc51o1r3j + 0 ) ; } } } if ( ( rtDW .
cfixiwqkrp >= ssGetT ( rtS ) ) && ( rtDW . ekrxxg0erb >= ssGetT ( rtS ) ) ) {
cnxr3xxpnr = 0.0 ; } else { cnxr3xxpnr = rtDW . cfixiwqkrp ; lastU = & rtDW .
du12egghrd ; if ( rtDW . cfixiwqkrp < rtDW . ekrxxg0erb ) { if ( rtDW .
ekrxxg0erb < ssGetT ( rtS ) ) { cnxr3xxpnr = rtDW . ekrxxg0erb ; lastU = &
rtDW . piennvgrqo ; } } else if ( rtDW . cfixiwqkrp >= ssGetT ( rtS ) ) {
cnxr3xxpnr = rtDW . ekrxxg0erb ; lastU = & rtDW . piennvgrqo ; } cnxr3xxpnr =
( rtB . eczoaexinb - * lastU ) / ( ssGetT ( rtS ) - cnxr3xxpnr ) ; } rtB .
cim5aoljt4 = ( ( ( fayf3pksv5 + bufyw0qqkf ) - ( rtB . g4yr0vtwax -
cnxr3xxpnr ) * rtP . cu ) - ( rtB . hkc51o1r3j - rtB . eczoaexinb ) * rtP .
ku ) * ( 1.0 / rtP . mu ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if (
rtDW . fmslhtsxbv . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . fmslhtsxbv . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. daw4mlgab4 + 0 ) ; } } { if ( rtDW . gqhh5yhvhz . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . gqhh5yhvhz . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . myws1id50y + 0 ) ; } } { if (
rtDW . erzoh5yp2e . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . erzoh5yp2e . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. ocia3xjh5x + 0 ) ; } } { if ( rtDW . bo14fpjqv4 . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . bo14fpjqv4 . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . dtyrmwdlrl + 0 ) ; } } }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { real_T * lastU ;
if ( rtDW . cfixiwqkrp == ( rtInf ) ) { rtDW . cfixiwqkrp = ssGetT ( rtS ) ;
lastU = & rtDW . du12egghrd ; } else if ( rtDW . ekrxxg0erb == ( rtInf ) ) {
rtDW . ekrxxg0erb = ssGetT ( rtS ) ; lastU = & rtDW . piennvgrqo ; } else if
( rtDW . cfixiwqkrp < rtDW . ekrxxg0erb ) { rtDW . cfixiwqkrp = ssGetT ( rtS
) ; lastU = & rtDW . du12egghrd ; } else { rtDW . ekrxxg0erb = ssGetT ( rtS )
; lastU = & rtDW . piennvgrqo ; } * lastU = rtB . eczoaexinb ;
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> oiut1i5lm5 = rtB .
myws1id50y ; _rtXdot -> e422fmwxvg = rtB . g4yr0vtwax ; _rtXdot -> gndnjdd0up
= rtB . ocia3xjh5x ; _rtXdot -> oksa0vt5t1 = rtB . cim5aoljt4 ; } void
MdlProjection ( void ) { } void MdlTerminate ( void ) { { if ( rtDW .
l4hk4ayfzr . AQHandles ) { sdiTerminateStreaming ( & rtDW . l4hk4ayfzr .
AQHandles ) ; } } { if ( rtDW . nqfjjqfmpd . AQHandles ) {
sdiTerminateStreaming ( & rtDW . nqfjjqfmpd . AQHandles ) ; } } { if ( rtDW .
dkvh2msww4 . AQHandles ) { sdiTerminateStreaming ( & rtDW . dkvh2msww4 .
AQHandles ) ; } } { if ( rtDW . fmslhtsxbv . AQHandles ) {
sdiTerminateStreaming ( & rtDW . fmslhtsxbv . AQHandles ) ; } } { if ( rtDW .
gqhh5yhvhz . AQHandles ) { sdiTerminateStreaming ( & rtDW . gqhh5yhvhz .
AQHandles ) ; } } { if ( rtDW . erzoh5yp2e . AQHandles ) {
sdiTerminateStreaming ( & rtDW . erzoh5yp2e . AQHandles ) ; } } { if ( rtDW .
bo14fpjqv4 . AQHandles ) { sdiTerminateStreaming ( & rtDW . bo14fpjqv4 .
AQHandles ) ; } } } static void mr_ModelEquationsDOF2_cacheDataAsMxArray (
mxArray * destArray , mwIndex i , int j , const void * srcData , size_t
numBytes ) ; static void mr_ModelEquationsDOF2_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) {
mxArray * newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void mr_ModelEquationsDOF2_restoreDataFromMxArray (
void * destData , const mxArray * srcArray , mwIndex i , int j , size_t
numBytes ) ; static void mr_ModelEquationsDOF2_restoreDataFromMxArray ( void
* destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes )
{ memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void
mr_ModelEquationsDOF2_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex
i , int j , uint_T bitVal ) ; static void
mr_ModelEquationsDOF2_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex
i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_ModelEquationsDOF2_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_ModelEquationsDOF2_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_ModelEquationsDOF2_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_ModelEquationsDOF2_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_ModelEquationsDOF2_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void
mr_ModelEquationsDOF2_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_ModelEquationsDOF2_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_ModelEquationsDOF2_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( double ) fieldVal ) ) ; } static uint_T
mr_ModelEquationsDOF2_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_ModelEquationsDOF2_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_ModelEquationsDOF2_GetDWork ( ) {
static const char * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX"
, } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_ModelEquationsDOF2_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) &
( rtB ) , sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 4 ] =
{ "rtDW.cfixiwqkrp" , "rtDW.du12egghrd" , "rtDW.ekrxxg0erb" ,
"rtDW.piennvgrqo" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 , 4
, rtdwDataFieldNames ) ; mr_ModelEquationsDOF2_cacheDataAsMxArray ( rtdwData
, 0 , 0 , ( const void * ) & ( rtDW . cfixiwqkrp ) , sizeof ( rtDW .
cfixiwqkrp ) ) ; mr_ModelEquationsDOF2_cacheDataAsMxArray ( rtdwData , 0 , 1
, ( const void * ) & ( rtDW . du12egghrd ) , sizeof ( rtDW . du12egghrd ) ) ;
mr_ModelEquationsDOF2_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void *
) & ( rtDW . ekrxxg0erb ) , sizeof ( rtDW . ekrxxg0erb ) ) ;
mr_ModelEquationsDOF2_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void *
) & ( rtDW . piennvgrqo ) , sizeof ( rtDW . piennvgrqo ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_ModelEquationsDOF2_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_ModelEquationsDOF2_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW ,
0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber (
ssDW , 0 , 1 ) ; mr_ModelEquationsDOF2_restoreDataFromMxArray ( ( void * ) &
( rtDW . cfixiwqkrp ) , rtdwData , 0 , 0 , sizeof ( rtDW . cfixiwqkrp ) ) ;
mr_ModelEquationsDOF2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
du12egghrd ) , rtdwData , 0 , 1 , sizeof ( rtDW . du12egghrd ) ) ;
mr_ModelEquationsDOF2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ekrxxg0erb ) , rtdwData , 0 , 2 , sizeof ( rtDW . ekrxxg0erb ) ) ;
mr_ModelEquationsDOF2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
piennvgrqo ) , rtdwData , 0 , 3 , sizeof ( rtDW . piennvgrqo ) ) ; } }
mxArray * mr_ModelEquationsDOF2_GetSimStateDisallowedBlocks ( ) { mxArray *
data = mxCreateCellMatrix ( 7 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static
const char * blockType [ 7 ] = { "Scope" , "Scope" , "Scope" , "Scope" ,
"Scope" , "Scope" , "Scope" , } ; static const char * blockPath [ 7 ] = {
 "ModelEquationsDOF2/  Xb Displacement (purple)  Velocity (purple)  Acceleration () SWS ()"
, "ModelEquationsDOF2/SWS" , "ModelEquationsDOF2/Scope" ,
"ModelEquationsDOF2/Scope1" , "ModelEquationsDOF2/Scope_Xs_DOT5" ,
"ModelEquationsDOF2/Scope_Xu_DOT6" ,
 "ModelEquationsDOF2/Unsprung = Displacement (yellow)  Velocity (purple)  Acceleration (purple)"
, } ; static const int reason [ 7 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , } ; for (
subs [ 0 ] = 0 ; subs [ 0 ] < 7 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateDoubleScalar ( ( double ) reason [ subs [ 0 ] ] ) ) ; } }
return data ; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
4 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 3 ) ;
ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 38 ) ;
ssSetNumBlockIO ( rtS , 9 ) ; ssSetNumBlockParams ( rtS , 210 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.001 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2140124014U ) ; ssSetChecksumVal ( rtS , 1 ,
4103400140U ) ; ssSetChecksumVal ( rtS , 2 , 1883289858U ) ; ssSetChecksumVal
( rtS , 3 , 543412518U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0
, sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { ssSetY ( rtS , & rtY ) ; ( void ) memset ( & rtY , 0 , sizeof (
ExtY ) ) ; ssSetWorkSizeInBytes ( rtS , sizeof ( rtY ) , "YOut" ) ; } {
real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void )
memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) &
rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof
( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T *
) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo
) ; dtInfo . numDataTypes = 23 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [
0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable
= & rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
ModelEquationsDOF2_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive
( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "ModelEquationsDOF2" ) ;
ssSetPath ( rtS , "ModelEquationsDOF2" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 100.0 ) ; ssSetStepSize ( rtS , 0.001 ) ;
ssSetFixedStepSize ( rtS , 0.001 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 }
; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "ModelEquationsDOF2/Xs_DOT" ,
"ModelEquationsDOF2/Xu_DOT\n" , "ModelEquationsDOF2/Xs_DOT_DOT" ,
"ModelEquationsDOF2/Xu_DOT_DOT\n" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 4 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 4 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . oiut1i5lm5 ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . e422fmwxvg ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . gndnjdd0up ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . oksa0vt5t1 ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; { static void * rt_LoggedOutputSignalPtrs [ ] = { & rtY .
p5l14loct1 , & rtY . elahtxe02w , & rtY . lb1ncf1g1s } ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( ( LogSignalPtrsType )
rt_LoggedOutputSignalPtrs ) ) ; } { static int_T rt_LoggedOutputWidths [ ] =
{ 1 , 1 , 1 } ; static int_T rt_LoggedOutputNumDimensions [ ] = { 1 , 1 , 1 }
; static int_T rt_LoggedOutputDimensions [ ] = { 1 , 1 , 1 } ; static
boolean_T rt_LoggedOutputIsVarDims [ ] = { 0 , 0 , 0 } ; static void *
rt_LoggedCurrentSignalDimensions [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ;
static int_T rt_LoggedCurrentSignalDimensionsSize [ ] = { 4 , 4 , 4 } ;
static BuiltInDTypeId rt_LoggedOutputDataTypeIds [ ] = { SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedOutputComplexSignals [ ] = {
0 , 0 , 0 } ; static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs [
] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedOutputLabels_0 [ ] = { "Xs" } ; static const char_T *
rt_LoggedOutputBlockNames_0 [ ] = { "ModelEquationsDOF2/Out6" } ; static
const char_T * rt_LoggedOutputLabels_1 [ ] = { "Xu" } ; static const char_T *
rt_LoggedOutputBlockNames_1 [ ] = { "ModelEquationsDOF2/Out7" } ; static
const char_T * rt_LoggedOutputLabels_2 [ ] = { "Xb_DOT_DOT" } ; static const
char_T * rt_LoggedOutputBlockNames_2 [ ] = { "ModelEquationsDOF2/Out1" } ;
static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } } ; static RTWLogSignalInfo rt_LoggedOutputSignalInfo [ ] = { { 1 ,
rt_LoggedOutputWidths , rt_LoggedOutputNumDimensions ,
rt_LoggedOutputDimensions , rt_LoggedOutputIsVarDims ,
rt_LoggedCurrentSignalDimensions , rt_LoggedCurrentSignalDimensionsSize ,
rt_LoggedOutputDataTypeIds , rt_LoggedOutputComplexSignals , ( NULL ) ,
rt_LoggingPreprocessingFcnPtrs , { rt_LoggedOutputLabels_0 } , ( NULL ) , (
NULL ) , ( NULL ) , { rt_LoggedOutputBlockNames_0 } , { ( NULL ) } , ( NULL )
, rt_RTWLogDataTypeConvert , ( NULL ) } , { 1 , rt_LoggedOutputWidths + 1 ,
rt_LoggedOutputNumDimensions + 1 , rt_LoggedOutputDimensions + 1 ,
rt_LoggedOutputIsVarDims + 1 , rt_LoggedCurrentSignalDimensions + 1 ,
rt_LoggedCurrentSignalDimensionsSize + 1 , rt_LoggedOutputDataTypeIds + 1 ,
rt_LoggedOutputComplexSignals + 1 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 1 , { rt_LoggedOutputLabels_1 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_1 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 1 , ( NULL ) } , { 1 , rt_LoggedOutputWidths + 2 ,
rt_LoggedOutputNumDimensions + 2 , rt_LoggedOutputDimensions + 2 ,
rt_LoggedOutputIsVarDims + 2 , rt_LoggedCurrentSignalDimensions + 2 ,
rt_LoggedCurrentSignalDimensionsSize + 2 , rt_LoggedOutputDataTypeIds + 2 ,
rt_LoggedOutputComplexSignals + 2 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 2 , { rt_LoggedOutputLabels_2 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_2 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 2 , ( NULL ) } } ; rtliSetLogYSignalInfo (
ssGetRTWLogInfo ( rtS ) , rt_LoggedOutputSignalInfo ) ;
rt_LoggedCurrentSignalDimensions [ 0 ] = & rt_LoggedOutputWidths [ 0 ] ;
rt_LoggedCurrentSignalDimensions [ 1 ] = & rt_LoggedOutputWidths [ 1 ] ;
rt_LoggedCurrentSignalDimensions [ 2 ] = & rt_LoggedOutputWidths [ 2 ] ; }
rtliSetLogY ( ssGetRTWLogInfo ( rtS ) ,
"tmp_raccel_yout1,tmp_raccel_yout2,tmp_raccel_yout3" ) ; } { static struct
_ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 ) ; } {
static ssPeriodicStatesInfo periodicStatesInfo ; ssSetPeriodicStatesInfo (
rtS , & periodicStatesInfo ) ; } { static ssJacobianPerturbationBounds
jacobianPerturbationBounds ; ssSetJacobianPerturbationBounds ( rtS , &
jacobianPerturbationBounds ) ; } { static ssSolverInfo slvrInfo ; static
boolean_T contStatesDisabled [ 4 ] ; ssSetNumNonContDerivSigInfos ( rtS , 0 )
; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS , &
slvrInfo ) ; ssSetSolverName ( rtS , "ode4" ) ; ssSetVariableStepSolver ( rtS
, 0 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; }
ssSetChecksumVal ( rtS , 0 , 2140124014U ) ; ssSetChecksumVal ( rtS , 1 ,
4103400140U ) ; ssSetChecksumVal ( rtS , 2 , 1883289858U ) ; ssSetChecksumVal
( rtS , 3 , 543412518U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_ModelEquationsDOF2_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_ModelEquationsDOF2_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_ModelEquationsDOF2_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = - 1 ; void MdlOutputsParameterSampleTime
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
