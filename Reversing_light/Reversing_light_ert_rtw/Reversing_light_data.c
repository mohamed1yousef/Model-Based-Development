/*
 * File: Reversing_light_data.c
 *
 * Code generated for Simulink model 'Reversing_light'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Mar  1 15:19:37 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Reversing_light.h"
#include "Reversing_light_private.h"

/* Block parameters (default storage) */
P_Reversing_light_T Reversing_light_P = {
  /* Mask Parameter: Counter_InitialCount
   * Referenced by: '<S3>/Counter'
   */
  1U,

  /* Mask Parameter: Counter_InitialCount_l
   * Referenced by: '<S5>/Counter'
   */
  1U,

  /* Mask Parameter: Counter_InitialCount_n
   * Referenced by: '<S4>/Counter'
   */
  1U,

  /* Expression: .01
   * Referenced by: '<Root>/Digital Input2'
   */
  0.01,

  /* Expression: .01
   * Referenced by: '<Root>/Digital Input1'
   */
  0.01,

  /* Expression: .01
   * Referenced by: '<Root>/Digital Input'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S12>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S1>/Pulse Generator'
   */
  250.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S1>/Pulse Generator'
   */
  125.0,

  /* Expression: 0
   * Referenced by: '<S1>/Pulse Generator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_p
   * Referenced by: '<S2>/Pulse Generator'
   */
  250.0,

  /* Computed Parameter: PulseGenerator_Duty_m
   * Referenced by: '<S2>/Pulse Generator'
   */
  125.0,

  /* Expression: 0
   * Referenced by: '<S2>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S3>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_b
   * Referenced by: '<S5>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_d
   * Referenced by: '<S4>/Merge'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
