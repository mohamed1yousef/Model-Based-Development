/*
 * File: Automated_Irrigation_Control_Sy.c
 *
 * Code generated for Simulink model 'Automated_Irrigation_Control_Sy'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Feb 17 20:59:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (8-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Automated_Irrigation_Control_Sy.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Automated_Irrigation_Control_Sy_step(void)
{
  /* Outport: '<Root>/water_pump_statues' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/Soil_moisture_sensor'
   *  Product: '<S1>/Product'
   *  RelationalOperator: '<S2>/Compare'
   *  RelationalOperator: '<S3>/Compare'
   */
  rtY.water_pump_statues = rtU.Soil_moisture_sensor >= 50.0 ? (uint16_T)
    (rtU.Soil_moisture_sensor <= 75.0) : 0U;
}

/* Model initialize function */
void Automated_Irrigation_Control_Sy_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
