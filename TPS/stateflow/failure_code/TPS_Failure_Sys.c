/*
 * File: TPS_Failure_Sys.c
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

#include "TPS_Failure_Sys.h"
#include "TPS_Failure_Sys_private.h"

/* Block states (default storage) */
DW_TPS_Failure_Sys_T TPS_Failure_Sys_DW;

/* External inputs (root inport signals with default storage) */
ExtU_TPS_Failure_Sys_T TPS_Failure_Sys_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TPS_Failure_Sys_T TPS_Failure_Sys_Y;

/* Real-time model */
RT_MODEL_TPS_Failure_Sys_T TPS_Failure_Sys_M_;
RT_MODEL_TPS_Failure_Sys_T *const TPS_Failure_Sys_M = &TPS_Failure_Sys_M_;

/* Model step function */
void TPS_Failure_Sys_step(void)
{
  /* Chart: '<Root>/TPS_Coherency1' */
  if (TPS_Failure_Sys_DW.is_active_c1_TPS_Failure_Sys == 0U) {
    TPS_Failure_Sys_DW.is_active_c1_TPS_Failure_Sys = 1U;

    /* Outport: '<Root>/sen_1_failure' incorporates:
     *  Inport: '<Root>/sensor_1'
     */
    TPS_Failure_Sys_Y.sen_1_failure = ((TPS_Failure_Sys_U.sensor_1 < .5) ||
      (TPS_Failure_Sys_U.sensor_1 > 4.5));

    /* Outport: '<Root>/System_Coherency' incorporates:
     *  Inport: '<Root>/sensor_1'
     *  Inport: '<Root>/sensor_2'
     */
    TPS_Failure_Sys_Y.System_Coherency = (TPS_Failure_Sys_U.sensor_1 +
      TPS_Failure_Sys_U.sensor_2 != 5.0);

    /* Outport: '<Root>/sen_2_failure' incorporates:
     *  Inport: '<Root>/sensor_2'
     */
    TPS_Failure_Sys_Y.sen_2_failure = ((TPS_Failure_Sys_U.sensor_2 < .5) ||
      (TPS_Failure_Sys_U.sensor_2 > 4.5));
  } else {
    /* Outport: '<Root>/sen_1_failure' incorporates:
     *  Inport: '<Root>/sensor_1'
     */
    TPS_Failure_Sys_Y.sen_1_failure = ((TPS_Failure_Sys_U.sensor_1 < .5) ||
      (TPS_Failure_Sys_U.sensor_1 > 4.5));

    /* Outport: '<Root>/System_Coherency' incorporates:
     *  Inport: '<Root>/sensor_1'
     *  Inport: '<Root>/sensor_2'
     */
    TPS_Failure_Sys_Y.System_Coherency = (TPS_Failure_Sys_U.sensor_1 +
      TPS_Failure_Sys_U.sensor_2 != 5.0);

    /* Outport: '<Root>/sen_2_failure' incorporates:
     *  Inport: '<Root>/sensor_2'
     */
    TPS_Failure_Sys_Y.sen_2_failure = ((TPS_Failure_Sys_U.sensor_2 < .5) ||
      (TPS_Failure_Sys_U.sensor_2 > 4.5));
  }

  /* End of Chart: '<Root>/TPS_Coherency1' */
}

/* Model initialize function */
void TPS_Failure_Sys_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void TPS_Failure_Sys_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
