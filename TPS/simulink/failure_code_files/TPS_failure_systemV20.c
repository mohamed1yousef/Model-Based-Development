/*
 * File: TPS_failure_systemV20.c
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

#include "TPS_failure_systemV20.h"
#include "TPS_failure_systemV20_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_TPS_failure_systemV20_T TPS_failure_systemV20_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TPS_failure_systemV20_T TPS_failure_systemV20_Y;

/* Real-time model */
RT_MODEL_TPS_failure_systemV2_T TPS_failure_systemV20_M_;
RT_MODEL_TPS_failure_systemV2_T *const TPS_failure_systemV20_M =
  &TPS_failure_systemV20_M_;

/* Model step function */
void TPS_failure_systemV20_step(void)
{
  /* Outport: '<Root>/Sensor1_Failure_Sig' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/TPS_sensor1'
   *  Logic: '<S1>/OR'
   *  RelationalOperator: '<S2>/Compare'
   *  RelationalOperator: '<S3>/Compare'
   */
  TPS_failure_systemV20_Y.Sensor1_Failure_Sig =
    ((TPS_failure_systemV20_U.TPS_sensor1 > 4.5F) ||
     (TPS_failure_systemV20_U.TPS_sensor1 < 0.5F));

  /* Outport: '<Root>/TPS_System_failure' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Inport: '<Root>/TPS_sensor2'
   *  Logic: '<S1>/OR1'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   */
  TPS_failure_systemV20_Y.TPS_System_failure =
    ((TPS_failure_systemV20_U.TPS_sensor2 > 4.5F) ||
     (TPS_failure_systemV20_U.TPS_sensor2 < 0.5F));

  /* Outport: '<Root>/Sensor2_Failure_Sig' incorporates:
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/TPS_sensor1'
   *  Inport: '<Root>/TPS_sensor2'
   *  RelationalOperator: '<S6>/Compare'
   *  Sum: '<S1>/Add'
   */
  TPS_failure_systemV20_Y.Sensor2_Failure_Sig =
    (TPS_failure_systemV20_U.TPS_sensor1 + TPS_failure_systemV20_U.TPS_sensor2
     != 5.0F);
}

/* Model initialize function */
void TPS_failure_systemV20_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void TPS_failure_systemV20_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
