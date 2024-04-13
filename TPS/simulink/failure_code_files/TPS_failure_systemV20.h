/*
 * File: TPS_failure_systemV20.h
 *
 * Code generated for Simulink model 'TPS_failure_systemV20'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Apr 13 17:12:00 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TPS_failure_systemV20_h_
#define RTW_HEADER_TPS_failure_systemV20_h_
#ifndef TPS_failure_systemV20_COMMON_INCLUDES_
# define TPS_failure_systemV20_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                              /* TPS_failure_systemV20_COMMON_INCLUDES_ */

#include "TPS_failure_systemV20_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T TPS_sensor1;                /* '<Root>/TPS_sensor1' */
  real32_T TPS_sensor2;                /* '<Root>/TPS_sensor2' */
} ExtU_TPS_failure_systemV20_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T Sensor1_Failure_Sig;       /* '<Root>/Sensor1_Failure_Sig' */
  boolean_T Sensor2_Failure_Sig;       /* '<Root>/Sensor2_Failure_Sig' */
  boolean_T TPS_System_failure;        /* '<Root>/TPS_System_failure' */
} ExtY_TPS_failure_systemV20_T;

/* Real-time Model Data Structure */
struct tag_RTM_TPS_failure_systemV20_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_TPS_failure_systemV20_T TPS_failure_systemV20_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TPS_failure_systemV20_T TPS_failure_systemV20_Y;

/* Model entry point functions */
extern void TPS_failure_systemV20_initialize(void);
extern void TPS_failure_systemV20_step(void);
extern void TPS_failure_systemV20_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TPS_failure_systemV2_T *const TPS_failure_systemV20_M;

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
 * '<Root>' : 'TPS_failure_systemV20'
 * '<S1>'   : 'TPS_failure_systemV20/TPS_failure_system'
 * '<S2>'   : 'TPS_failure_systemV20/TPS_failure_system/Compare To Constant'
 * '<S3>'   : 'TPS_failure_systemV20/TPS_failure_system/Compare To Constant1'
 * '<S4>'   : 'TPS_failure_systemV20/TPS_failure_system/Compare To Constant2'
 * '<S5>'   : 'TPS_failure_systemV20/TPS_failure_system/Compare To Constant3'
 * '<S6>'   : 'TPS_failure_systemV20/TPS_failure_system/Compare To Constant4'
 */
#endif                                 /* RTW_HEADER_TPS_failure_systemV20_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
