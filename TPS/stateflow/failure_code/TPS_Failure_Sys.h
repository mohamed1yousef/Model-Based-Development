/*
 * File: TPS_Failure_Sys.h
 *
 * Code generated for Simulink model 'TPS_Failure_Sys'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Apr 13 17:26:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TPS_Failure_Sys_h_
#define RTW_HEADER_TPS_Failure_Sys_h_
#ifndef TPS_Failure_Sys_COMMON_INCLUDES_
# define TPS_Failure_Sys_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TPS_Failure_Sys_COMMON_INCLUDES_ */

#include "TPS_Failure_Sys_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c1_TPS_Failure_Sys;/* '<Root>/TPS_Coherency1' */
} DW_TPS_Failure_Sys_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T sensor_1;                     /* '<Root>/sensor_1' */
  real_T sensor_2;                     /* '<Root>/sensor_2' */
} ExtU_TPS_Failure_Sys_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T sen_1_failure;             /* '<Root>/sen_1_failure' */
  boolean_T sen_2_failure;             /* '<Root>/sen_2_failure' */
  real_T System_Coherency;             /* '<Root>/System_Coherency' */
} ExtY_TPS_Failure_Sys_T;

/* Real-time Model Data Structure */
struct tag_RTM_TPS_Failure_Sys_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_TPS_Failure_Sys_T TPS_Failure_Sys_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_TPS_Failure_Sys_T TPS_Failure_Sys_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TPS_Failure_Sys_T TPS_Failure_Sys_Y;

/* Model entry point functions */
extern void TPS_Failure_Sys_initialize(void);
extern void TPS_Failure_Sys_step(void);
extern void TPS_Failure_Sys_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TPS_Failure_Sys_T *const TPS_Failure_Sys_M;

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
 * '<Root>' : 'TPS_Failure_Sys'
 * '<S1>'   : 'TPS_Failure_Sys/TPS_Coherency1'
 */
#endif                                 /* RTW_HEADER_TPS_Failure_Sys_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
