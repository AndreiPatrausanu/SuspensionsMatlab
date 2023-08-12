#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "ModelEquationsDOF2_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "ModelEquationsDOF2.h"
#include "ModelEquationsDOF2_capi.h"
#include "ModelEquationsDOF2_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"ModelEquationsDOF2/Abs" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1
, 0 , TARGET_STRING ( "ModelEquationsDOF2/Clock" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "ModelEquationsDOF2/Gain16" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"ModelEquationsDOF2/Gain17" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 4 , 0 , TARGET_STRING ( "ModelEquationsDOF2/Xs_DOT" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"ModelEquationsDOF2/Xs_DOT_DOT" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 6 , 0 , TARGET_STRING ( "ModelEquationsDOF2/Xu_DOT " ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"ModelEquationsDOF2/Xu_DOT_DOT " ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 8 , 0 , TARGET_STRING ( "ModelEquationsDOF2/1-D Lookup Table" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 9 , TARGET_STRING ( "ModelEquationsDOF2/Xs_DOT" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 10 , TARGET_STRING (
"ModelEquationsDOF2/Xs_DOT_DOT" ) , TARGET_STRING ( "InitialCondition" ) , 0
, 0 , 0 } , { 11 , TARGET_STRING ( "ModelEquationsDOF2/Xu_DOT " ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 12 , TARGET_STRING (
"ModelEquationsDOF2/Xu_DOT_DOT " ) , TARGET_STRING ( "InitialCondition" ) , 0
, 0 , 0 } , { 13 , TARGET_STRING ( "ModelEquationsDOF2/1-D Lookup Table" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 1 , 0 } , { 0 , ( NULL ) ,
( NULL ) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ;
static const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] =
{ { 14 , 0 , TARGET_STRING ( "ModelEquationsDOF2/Out6" ) , TARGET_STRING (
"Xs" ) , 1 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"ModelEquationsDOF2/Out7" ) , TARGET_STRING ( "Xu" ) , 2 , 0 , 0 , 0 , 0 } ,
{ 16 , 0 , TARGET_STRING ( "ModelEquationsDOF2/Out1" ) , TARGET_STRING (
"Xb_DOT_DOT" ) , 3 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0
, 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ]
= { { 17 , TARGET_STRING ( "cs" ) , 0 , 0 , 0 } , { 18 , TARGET_STRING ( "cu"
) , 0 , 0 , 0 } , { 19 , TARGET_STRING ( "ks" ) , 0 , 0 , 0 } , { 20 ,
TARGET_STRING ( "ku" ) , 0 , 0 , 0 } , { 21 , TARGET_STRING ( "ms" ) , 0 , 0
, 0 } , { 22 , TARGET_STRING ( "mu" ) , 0 , 0 , 0 } , { 23 , TARGET_STRING (
"road_front_wheel" ) , 0 , 1 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . dtyrmwdlrl , & rtB . g0ldcin0om ,
& rtB . ocia3xjh5x , & rtB . cim5aoljt4 , & rtB . daw4mlgab4 , & rtB .
myws1id50y , & rtB . hkc51o1r3j , & rtB . g4yr0vtwax , & rtB . eczoaexinb , &
rtP . Xs_DOT_IC , & rtP . Xs_DOT_DOT_IC , & rtP . Xu_DOT_IC , & rtP .
Xu_DOT_DOT_IC , & rtP . uDLookupTable_bp01Data [ 0 ] , & rtY . p5l14loct1 , &
rtY . elahtxe02w , & rtY . lb1ncf1g1s , & rtP . cs , & rtP . cu , & rtP . ks
, & rtP . ku , & rtP . ms , & rtP . mu , & rtP . road_front_wheel [ 0 ] , } ;
static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 1 , 100 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [
] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0
} , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [
0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 9 ,
rtRootInputs , 0 , rtRootOutputs , 3 } , { rtBlockParameters , 5 ,
rtModelParameters , 7 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2140124014U , 4103400140U , 1883289858U , 543412518U } , ( NULL ) , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * ModelEquationsDOF2_GetCAPIStaticMap ( void )
{ return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void ModelEquationsDOF2_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion (
( * rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void ModelEquationsDOF2_host_InitializeDataMapInfo (
ModelEquationsDOF2_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
