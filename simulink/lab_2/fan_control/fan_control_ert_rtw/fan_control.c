/*
 * File: fan_control.c
 *
 * Code generated for Simulink model 'fan_control'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Feb  6 16:33:33 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "fan_control.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void fan_control_step(void)
{
  /* Outport: '<Root>/fan_signal' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Inport: '<Root>/temp_1'
   *  Inport: '<Root>/temp_3'
   *  Logic: '<S1>/OR'
   *  RelationalOperator: '<S1>/GreaterThan'
   *  RelationalOperator: '<S1>/GreaterThan1'
   */
  rtY.fan_signal = ((rtU.temp_3 < 50.0) && (rtU.temp_1 > 25.0));
}

/* Model initialize function */
void fan_control_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
