/*
 * File: TPS_Logic_Stateflow.h
 *
 * Code generated for Simulink model 'TPS_Logic_Stateflow'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Apr 13 17:16:13 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TPS_Logic_Stateflow_h_
#define RTW_HEADER_TPS_Logic_Stateflow_h_
#ifndef TPS_Logic_Stateflow_COMMON_INCLUDES_
# define TPS_Logic_Stateflow_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                /* TPS_Logic_Stateflow_COMMON_INCLUDES_ */

#include "TPS_Logic_Stateflow_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_TPS_Logic_Stateflo;/* '<Root>/TPS_Logic' */
} DW_TPS_Logic_Stateflow_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T postion;                      /* '<Root>/postion' */
} ExtU_TPS_Logic_Stateflow_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T voltage_nom;                  /* '<Root>/voltage_nom' */
  real_T voltage_nom1;                 /* '<Root>/voltage_nom1' */
} ExtY_TPS_Logic_Stateflow_T;

/* Real-time Model Data Structure */
struct tag_RTM_TPS_Logic_Stateflow_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_TPS_Logic_Stateflow_T TPS_Logic_Stateflow_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_TPS_Logic_Stateflow_T TPS_Logic_Stateflow_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TPS_Logic_Stateflow_T TPS_Logic_Stateflow_Y;

/* Model entry point functions */
extern void TPS_Logic_Stateflow_initialize(void);
extern void TPS_Logic_Stateflow_step(void);
extern void TPS_Logic_Stateflow_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TPS_Logic_Stateflow_T *const TPS_Logic_Stateflow_M;

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
 * '<Root>' : 'TPS_Logic_Stateflow'
 * '<S1>'   : 'TPS_Logic_Stateflow/TPS_Logic'
 */
#endif                                 /* RTW_HEADER_TPS_Logic_Stateflow_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
