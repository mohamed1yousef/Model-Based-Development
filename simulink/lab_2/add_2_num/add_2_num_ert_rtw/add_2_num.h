/*
 * File: add_2_num.h
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

#ifndef RTW_HEADER_add_2_num_h_
#define RTW_HEADER_add_2_num_h_
#ifndef add_2_num_COMMON_INCLUDES_
# define add_2_num_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* add_2_num_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T num1;                         /* '<Root>/num1' */
  real_T num2;                         /* '<Root>/num2' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T sum;                          /* '<Root>/sum' */
} ExtY;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void add_2_num_initialize(void);
extern void add_2_num_step(void);

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
 * '<Root>' : 'add_2_num'
 * '<S1>'   : 'add_2_num/add_two_numbers'
 */
#endif                                 /* RTW_HEADER_add_2_num_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
