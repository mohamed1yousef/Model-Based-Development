/*
 * File: Reversing_light.h
 *
 * Code generated for Simulink model 'Reversing_light'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Mar  6 01:02:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Reversing_light_h_
#define RTW_HEADER_Reversing_light_h_
#include <stddef.h>
#include "rtwtypes.h"
#include <float.h>
#include <math.h>
#include <stddef.h>
#ifndef Reversing_light_COMMON_INCLUDES_
# define Reversing_light_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* Reversing_light_COMMON_INCLUDES_ */

/* Model Code Variants */
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define Reversing_light_M              (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef struct_tag_E7ZjpEHEQzzHgi4oOkm0RC
#define struct_tag_E7ZjpEHEQzzHgi4oOkm0RC

struct tag_E7ZjpEHEQzzHgi4oOkm0RC
{
  int16_T __dummy;
};

#endif                                 /*struct_tag_E7ZjpEHEQzzHgi4oOkm0RC*/

#ifndef typedef_b_arduinodriver_ArduinoDigitalI
#define typedef_b_arduinodriver_ArduinoDigitalI

typedef struct tag_E7ZjpEHEQzzHgi4oOkm0RC b_arduinodriver_ArduinoDigitalI;

#endif                               /*typedef_b_arduinodriver_ArduinoDigitalI*/

#ifndef struct_tag_s24Tu6ETtsZe5SOuhjxVUG
#define struct_tag_s24Tu6ETtsZe5SOuhjxVUG

struct tag_s24Tu6ETtsZe5SOuhjxVUG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigitalI DigitalIODriverObj;
  real_T SampleTime;
};

#endif                                 /*struct_tag_s24Tu6ETtsZe5SOuhjxVUG*/

#ifndef typedef_codertarget_arduinobase_blocks_
#define typedef_codertarget_arduinobase_blocks_

typedef struct tag_s24Tu6ETtsZe5SOuhjxVUG codertarget_arduinobase_blocks_;

#endif                               /*typedef_codertarget_arduinobase_blocks_*/

#ifndef struct_tag_KPrkuOK6ssObybfxqijZPC
#define struct_tag_KPrkuOK6ssObybfxqijZPC

struct tag_KPrkuOK6ssObybfxqijZPC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigitalI DigitalIODriverObj;
};

#endif                                 /*struct_tag_KPrkuOK6ssObybfxqijZPC*/

#ifndef typedef_codertarget_arduinobase_block_d
#define typedef_codertarget_arduinobase_block_d

typedef struct tag_KPrkuOK6ssObybfxqijZPC codertarget_arduinobase_block_d;

#endif                               /*typedef_codertarget_arduinobase_block_d*/

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_blocks_ obj; /* '<Root>/Digital Input' */
  codertarget_arduinobase_blocks_ obj_h;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_blocks_ obj_b;/* '<Root>/Digital Input2' */
  codertarget_arduinobase_block_d obj_h5;/* '<Root>/Digital Output' */
  codertarget_arduinobase_block_d obj_g;/* '<Root>/Digital Output1' */
  real_T Delay_DSTATE[2];              /* '<S7>/Delay' */
  real_T Delay1_DSTATE[2];             /* '<S7>/Delay1' */
  real_T Delay;                        /* '<S7>/Delay' */
  real_T Delay1;                       /* '<S7>/Delay1' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  int32_T clockTickCounter_j;          /* '<S2>/Pulse Generator' */
  uint32_T Counter_ClkEphState;        /* '<S7>/Counter' */
  uint32_T Counter_RstEphState;        /* '<S7>/Counter' */
  uint32_T Counter_ClkEphState_l;      /* '<S3>/Counter' */
  uint32_T Counter1_ClkEphState;       /* '<S7>/Counter1' */
  uint32_T Counter1_RstEphState;       /* '<S7>/Counter1' */
  uint8_T Counter_Count;               /* '<S7>/Counter' */
  uint8_T Counter_Count_g;             /* '<S3>/Counter' */
  uint8_T Counter1_Count;              /* '<S7>/Counter1' */
  boolean_T TmpRTBAtANDInport1;        /* '<S1>/OR' */
  boolean_T TmpRTBAtANDInport1_m;      /* '<S2>/OR' */
  boolean_T TmpRTBAtANDInport1_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtANDInport2_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtANDInport1_Buffer0_h;/* synthesized block */
  boolean_T TmpRTBAtANDInport2_Buffer0_o;/* synthesized block */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External function called from main */
extern void Reversing_light_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Reversing_light_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Reversing_light_initialize(void);
extern void Reversing_light_step0(void);
extern void Reversing_light_step1(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Reversing_light'
 * '<S1>'   : 'Reversing_light/blinker_1'
 * '<S2>'   : 'Reversing_light/blinker_2'
 * '<S3>'   : 'Reversing_light/push_buttom on\off2'
 * '<S4>'   : 'Reversing_light/signals_organization'
 * '<S5>'   : 'Reversing_light/signals_organization1'
 * '<S6>'   : 'Reversing_light/slelecion_mode'
 * '<S7>'   : 'Reversing_light/switch_bettween_2buttom'
 * '<S8>'   : 'Reversing_light/push_buttom on\off2/MATLAB Function'
 * '<S9>'   : 'Reversing_light/slelecion_mode/Compare To Zero'
 * '<S10>'  : 'Reversing_light/switch_bettween_2buttom/MATLAB Function'
 * '<S11>'  : 'Reversing_light/switch_bettween_2buttom/MATLAB Function2'
 */
#endif                                 /* RTW_HEADER_Reversing_light_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
