/*
 * File: Reversing_light_types.h
 *
 * Code generated for Simulink model 'Reversing_light'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Mar  1 15:19:37 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Reversing_light_types_h_
#define RTW_HEADER_Reversing_light_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_E7ZjpEHEQzzHgi4oOkm0RC
#define struct_tag_E7ZjpEHEQzzHgi4oOkm0RC

struct tag_E7ZjpEHEQzzHgi4oOkm0RC
{
  int16_T __dummy;
};

#endif                                 /*struct_tag_E7ZjpEHEQzzHgi4oOkm0RC*/

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_E7ZjpEHEQzzHgi4oOkm0RC b_arduinodriver_ArduinoDigita_T;

#endif                               /*typedef_b_arduinodriver_ArduinoDigita_T*/

#ifndef struct_tag_s24Tu6ETtsZe5SOuhjxVUG
#define struct_tag_s24Tu6ETtsZe5SOuhjxVUG

struct tag_s24Tu6ETtsZe5SOuhjxVUG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
  real_T SampleTime;
};

#endif                                 /*struct_tag_s24Tu6ETtsZe5SOuhjxVUG*/

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_s24Tu6ETtsZe5SOuhjxVUG codertarget_arduinobase_block_T;

#endif                               /*typedef_codertarget_arduinobase_block_T*/

#ifndef struct_tag_KPrkuOK6ssObybfxqijZPC
#define struct_tag_KPrkuOK6ssObybfxqijZPC

struct tag_KPrkuOK6ssObybfxqijZPC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /*struct_tag_KPrkuOK6ssObybfxqijZPC*/

#ifndef typedef_codertarget_arduinobase_blo_d_T
#define typedef_codertarget_arduinobase_blo_d_T

typedef struct tag_KPrkuOK6ssObybfxqijZPC codertarget_arduinobase_blo_d_T;

#endif                               /*typedef_codertarget_arduinobase_blo_d_T*/

/* Parameters (default storage) */
typedef struct P_Reversing_light_T_ P_Reversing_light_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Reversing_light_T RT_MODEL_Reversing_light_T;

#endif                                 /* RTW_HEADER_Reversing_light_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
