/*
 * File: TPS_SensorV20.c
 *
 * Code generated for Simulink model 'TPS_SensorV20'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Apr 13 17:03:01 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TPS_SensorV20.h"
#include "TPS_SensorV20_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_TPS_SensorV20_T TPS_SensorV20_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TPS_SensorV20_T TPS_SensorV20_Y;

/* Real-time model */
RT_MODEL_TPS_SensorV20_T TPS_SensorV20_M_;
RT_MODEL_TPS_SensorV20_T *const TPS_SensorV20_M = &TPS_SensorV20_M_;

/* Model step function */
void TPS_SensorV20_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/TPS_Logic' */
  /* Outport: '<Root>/voltage' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Inport: '<Root>/position'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Add'
   */
  TPS_SensorV20_Y.voltage = TPS_SensorV20_U.position * -0.63661977236758138 +
    4.5;

  /* Outport: '<Root>/voltage1' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   *  Inport: '<Root>/position'
   *  Product: '<S1>/Product1'
   *  Sum: '<S1>/Add1'
   */
  TPS_SensorV20_Y.voltage1 = TPS_SensorV20_U.position * 0.63661977236758138 +
    0.5;

  /* End of Outputs for SubSystem: '<Root>/TPS_Logic' */
}

/* Model initialize function */
void TPS_SensorV20_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void TPS_SensorV20_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
