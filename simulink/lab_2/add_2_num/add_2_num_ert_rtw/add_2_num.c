/*
 * File: add_2_num.c
 *
 * Code generated for Simulink model 'add_2_num'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Feb  6 16:20:30 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "add_2_num.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void add_2_num_step(void)
{
  /* Outport: '<Root>/sum' incorporates:
   *  Inport: '<Root>/num1'
   *  Inport: '<Root>/num2'
   *  Sum: '<S1>/Add'
   */
  rtY.sum = rtU.num1 + rtU.num2;
}

/* Model initialize function */
void add_2_num_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
