/*
 * File: Reversing_light.h
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

#ifndef RTW_HEADER_Reversing_light_h_
#define RTW_HEADER_Reversing_light_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Reversing_light_COMMON_INCLUDES_
# define Reversing_light_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* Reversing_light_COMMON_INCLUDES_ */

#include "Reversing_light_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T OR;                        /* '<S1>/OR' */
  boolean_T OR_i;                      /* '<S2>/OR' */
} B_Reversing_light_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Input' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_block_T obj_b;/* '<Root>/Digital Input2' */
  codertarget_arduinobase_blo_d_T obj_h5;/* '<Root>/Digital Output' */
  codertarget_arduinobase_blo_d_T obj_g;/* '<Root>/Digital Output1' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  int32_T clockTickCounter_j;          /* '<S2>/Pulse Generator' */
  uint32_T Counter_ClkEphState;        /* '<S3>/Counter' */
  uint32_T Counter_ClkEphState_l;      /* '<S5>/Counter' */
  uint32_T Counter_ClkEphState_k;      /* '<S4>/Counter' */
  uint8_T Counter_Count;               /* '<S3>/Counter' */
  uint8_T Counter_Count_g;             /* '<S5>/Counter' */
  uint8_T Counter_Count_o;             /* '<S4>/Counter' */
} DW_Reversing_light_T;

/* Parameters (default storage) */
struct P_Reversing_light_T_ {
  uint8_T Counter_InitialCount;        /* Mask Parameter: Counter_InitialCount
                                        * Referenced by: '<S3>/Counter'
                                        */
  uint8_T Counter_InitialCount_l;      /* Mask Parameter: Counter_InitialCount_l
                                        * Referenced by: '<S5>/Counter'
                                        */
  uint8_T Counter_InitialCount_n;      /* Mask Parameter: Counter_InitialCount_n
                                        * Referenced by: '<S4>/Counter'
                                        */
  real_T DigitalInput2_SampleTime;     /* Expression: .01
                                        * Referenced by: '<Root>/Digital Input2'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: .01
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: .01
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S1>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S1>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T PulseGenerator_Amp_f;         /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_p; /* Computed Parameter: PulseGenerator_Period_p
                                   * Referenced by: '<S2>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_m;     /* Computed Parameter: PulseGenerator_Duty_m
                                     * Referenced by: '<S2>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_e;  /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S3>/Merge'
                                       */
  real_T Merge_InitialOutput_b;     /* Computed Parameter: Merge_InitialOutput_b
                                     * Referenced by: '<S5>/Merge'
                                     */
  real_T Merge_InitialOutput_d;     /* Computed Parameter: Merge_InitialOutput_d
                                     * Referenced by: '<S4>/Merge'
                                     */
};

/* Real-time Model Data Structure */
struct tag_RTM_Reversing_light_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Reversing_light_T Reversing_light_P;

/* Block signals (default storage) */
extern B_Reversing_light_T Reversing_light_B;

/* Block states (default storage) */
extern DW_Reversing_light_T Reversing_light_DW;

/* External function called from main */
extern void Reversing_light_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Reversing_light_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Reversing_light_initialize(void);
extern void Reversing_light_step0(void);
extern void Reversing_light_step1(void);
extern void Reversing_light_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Reversing_light_T *const Reversing_light_M;

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
 * '<S1>'   : 'Reversing_light/Reversing light'
 * '<S2>'   : 'Reversing_light/Reversing light1'
 * '<S3>'   : 'Reversing_light/push_buttom on\off'
 * '<S4>'   : 'Reversing_light/push_buttom on\off1'
 * '<S5>'   : 'Reversing_light/push_buttom on\off2'
 * '<S6>'   : 'Reversing_light/sgnals_organization'
 * '<S7>'   : 'Reversing_light/sgnals_organization1'
 * '<S8>'   : 'Reversing_light/slelecion_mode'
 * '<S9>'   : 'Reversing_light/push_buttom on\off/MATLAB Function'
 * '<S10>'  : 'Reversing_light/push_buttom on\off1/MATLAB Function'
 * '<S11>'  : 'Reversing_light/push_buttom on\off2/MATLAB Function'
 * '<S12>'  : 'Reversing_light/slelecion_mode/Compare To Zero'
 */
#endif                                 /* RTW_HEADER_Reversing_light_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
