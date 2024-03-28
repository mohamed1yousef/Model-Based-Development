/*
 * File: traffic_light_with_urgent_mange.c
 *
 * Code generated for Simulink model 'traffic_light_with_urgent_mange'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Mar 28 01:49:18 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "traffic_light_with_urgent_mange.h"

/* Named constants for Chart: '<Root>/traffic_light_with_urgent_manger' */
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_fault                       ((uint8_T)1U)
#define IN_go                          ((uint8_T)1U)
#define IN_normal                      ((uint8_T)2U)
#define IN_ready                       ((uint8_T)2U)
#define IN_start                       ((uint8_T)1U)
#define IN_stop                        ((uint8_T)3U)
#define IN_stop_e                      ((uint8_T)2U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void traffic_light_with_urgent_mange_step(void)
{
  /* Chart: '<Root>/traffic_light_with_urgent_manger' incorporates:
   *  Inport: '<Root>/urgent'
   */
  if (rtDW.temporalCounter_i1 < 1023U) {
    rtDW.temporalCounter_i1 = (uint16_T)(uint32_T)((uint32_T)
      rtDW.temporalCounter_i1 + 1UL);
  }

  if ((uint16_T)rtDW.is_active_c3_traffic_light_with == 0U) {
    rtDW.is_active_c3_traffic_light_with = 1U;
    rtDW.is_c3_traffic_light_with_urgent = IN_normal;
    rtDW.is_normal = IN_stop;
    rtDW.temporalCounter_i1 = 0U;

    /* Outport: '<Root>/red' */
    rtY.red = 1.0;
  } else if (rtDW.is_c3_traffic_light_with_urgent == IN_fault) {
    if (rtU.urgent == 0.0) {
      switch (rtDW.is_fault) {
       case IN_start:
        rtDW.is_fault = IN_NO_ACTIVE_CHILD;
        break;

       case IN_stop_e:
        rtDW.is_fault = IN_NO_ACTIVE_CHILD;
        break;
      }

      rtDW.is_c3_traffic_light_with_urgent = IN_normal;
      rtDW.is_normal = IN_stop;
      rtDW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/red' */
      rtY.red = 1.0;
    } else {
      switch (rtDW.is_fault) {
       case IN_start:
        break;

       default:
        /* case IN_stop: */
        if (rtU.urgent == 0.0) {
          rtDW.is_fault = IN_start;

          /* Outport: '<Root>/red' */
          rtY.red = 0.0;
        }
        break;
      }
    }
  } else {
    /* case IN_normal: */
    if (rtU.urgent == 1.0) {
      switch (rtDW.is_normal) {
       case IN_go:
        /* Outport: '<Root>/green' */
        rtY.green = 0.0;
        rtDW.is_normal = IN_NO_ACTIVE_CHILD;
        break;

       case IN_ready:
        /* Outport: '<Root>/yellow' */
        rtY.yellow = 0.0;
        rtDW.is_normal = IN_NO_ACTIVE_CHILD;
        break;

       case IN_stop:
        rtDW.is_normal = IN_NO_ACTIVE_CHILD;
        break;
      }

      rtDW.is_c3_traffic_light_with_urgent = IN_fault;
      rtDW.is_fault = IN_stop_e;

      /* Outport: '<Root>/red' */
      rtY.red = 1.0;
    } else {
      switch (rtDW.is_normal) {
       case IN_go:
        if (rtDW.temporalCounter_i1 >= 1000U) {
          /* Outport: '<Root>/green' */
          rtY.green = 0.0;
          rtDW.is_normal = IN_stop;
          rtDW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/red' */
          rtY.red = 1.0;
        }
        break;

       case IN_ready:
        if (rtDW.temporalCounter_i1 >= 1000U) {
          /* Outport: '<Root>/yellow' */
          rtY.yellow = 0.0;
          rtDW.is_normal = IN_go;
          rtDW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/green' */
          rtY.green = 1.0;
        }
        break;

       default:
        /* case IN_stop: */
        if (rtDW.temporalCounter_i1 >= 1000U) {
          /* Outport: '<Root>/red' */
          rtY.red = 0.0;
          rtDW.is_normal = IN_ready;
          rtDW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/yellow' */
          rtY.yellow = 1.0;
        }
        break;
      }
    }
  }

  /* End of Chart: '<Root>/traffic_light_with_urgent_manger' */
}

/* Model initialize function */
void traffic_light_with_urgent_mange_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
