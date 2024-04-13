/*
 * File: TPS_Logic_Stateflow.c
 *
 * Code generated for Simulink model 'TPS_Logic_Stateflow'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Apr 13 17:16:13 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TPS_Logic_Stateflow.h"
#include "TPS_Logic_Stateflow_private.h"

/* Block states (default storage) */
DW_TPS_Logic_Stateflow_T TPS_Logic_Stateflow_DW;

/* External inputs (root inport signals with default storage) */
ExtU_TPS_Logic_Stateflow_T TPS_Logic_Stateflow_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TPS_Logic_Stateflow_T TPS_Logic_Stateflow_Y;

/* Real-time model */
RT_MODEL_TPS_Logic_Stateflow_T TPS_Logic_Stateflow_M_;
RT_MODEL_TPS_Logic_Stateflow_T *const TPS_Logic_Stateflow_M =
  &TPS_Logic_Stateflow_M_;

/* Model step function */
void TPS_Logic_Stateflow_step(void)
{
  /* Chart: '<Root>/TPS_Logic' */
  if (TPS_Logic_Stateflow_DW.is_active_c3_TPS_Logic_Stateflo == 0U) {
    TPS_Logic_Stateflow_DW.is_active_c3_TPS_Logic_Stateflo = 1U;

    /* Outport: '<Root>/voltage_nom1' incorporates:
     *  Inport: '<Root>/postion'
     */
    TPS_Logic_Stateflow_Y.voltage_nom1 = TPS_Logic_Stateflow_U.postion *
      -6.2831853071795862 + 4.5;

    /* Outport: '<Root>/voltage_nom' incorporates:
     *  Inport: '<Root>/postion'
     */
    TPS_Logic_Stateflow_Y.voltage_nom = TPS_Logic_Stateflow_U.postion *
      6.2831853071795862 + 0.5;
  } else {
    /* Outport: '<Root>/voltage_nom1' incorporates:
     *  Inport: '<Root>/postion'
     */
    TPS_Logic_Stateflow_Y.voltage_nom1 = TPS_Logic_Stateflow_U.postion *
      -6.2831853071795862 + 4.5;

    /* Outport: '<Root>/voltage_nom' incorporates:
     *  Inport: '<Root>/postion'
     */
    TPS_Logic_Stateflow_Y.voltage_nom = TPS_Logic_Stateflow_U.postion *
      6.2831853071795862 + 0.5;
  }

  /* End of Chart: '<Root>/TPS_Logic' */
}

/* Model initialize function */
void TPS_Logic_Stateflow_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void TPS_Logic_Stateflow_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
