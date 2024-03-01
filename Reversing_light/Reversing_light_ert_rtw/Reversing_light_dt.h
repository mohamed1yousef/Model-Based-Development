/*
 * Reversing_light_dt.h
 *
 * Code generation for model "Reversing_light".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Fri Mar  1 15:19:37 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(codertarget_arduinobase_block_T),
  sizeof(codertarget_arduinobase_blo_d_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "codertarget_arduinobase_block_T",
  "codertarget_arduinobase_blo_d_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Reversing_light_B.OR), 8, 0, 2 }
  ,

  { (char_T *)(&Reversing_light_DW.obj), 14, 0, 3 },

  { (char_T *)(&Reversing_light_DW.obj_h5), 15, 0, 2 },

  { (char_T *)(&Reversing_light_DW.clockTickCounter), 6, 0, 2 },

  { (char_T *)(&Reversing_light_DW.Counter_ClkEphState), 7, 0, 3 },

  { (char_T *)(&Reversing_light_DW.Counter_Count), 3, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Reversing_light_P.Counter_InitialCount), 3, 0, 3 },

  { (char_T *)(&Reversing_light_P.DigitalInput2_SampleTime), 0, 0, 15 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] Reversing_light_dt.h */
