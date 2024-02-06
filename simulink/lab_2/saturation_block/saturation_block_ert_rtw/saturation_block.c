/*
 * File: saturation_block.c
 *
 * Code generated for Simulink model 'saturation_block'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Feb  6 16:42:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "saturation_block.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void saturation_block_step(void)
{
  /* Switch: '<S1>/Switch1' incorporates:
   *  Inport: '<Root>/input_signal'
   */
  if (rtU.input_signal > -0.5) {
    /* Switch: '<S1>/Switch' */
    if (rtU.input_signal > 0.5) {
      /* Outport: '<Root>/output_signal' incorporates:
       *  Constant: '<Root>/x'
       */
      rtY.output_signal = 0.5;
    } else {
      /* Outport: '<Root>/output_signal' */
      rtY.output_signal = rtU.input_signal;
    }

    /* End of Switch: '<S1>/Switch' */
  } else {
    /* Outport: '<Root>/output_signal' incorporates:
     *  Constant: '<Root>/y'
     */
    rtY.output_signal = -0.5;
  }

  /* End of Switch: '<S1>/Switch1' */
}

/* Model initialize function */
void saturation_block_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
