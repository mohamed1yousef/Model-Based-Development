/*
 * File: Active_Balancing_Subsystem.c
 *
 * Code generated for Simulink model 'Active_Balancing_Subsystem'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed May  1 15:32:19 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Active_Balancing_Subsystem.h"
#include "Active_Balancing_Subsystem_private.h"

/* Named constants for Chart: '<S1>/Active_Balancing_chart' */
#define Active_Balan_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Active_Balancin_IN_Leader_State ((uint8_T)1U)
#define Active_Balancin_IN_SW_Managment ((uint8_T)2U)
#define Active_Balancing_S_Target_Delta (0.1)
#define Active_Balancing_Subs_IN_Mode_A ((uint8_T)1U)
#define Active_Balancing_Subs_IN_Mode_B ((uint8_T)2U)

/* Block states (default storage) */
DW_Active_Balancing_Subsystem_T Active_Balancing_Subsystem_DW;

/* Real-time model */
RT_MODEL_Active_Balancing_Sub_T Active_Balancing_Subsystem_M_;
RT_MODEL_Active_Balancing_Sub_T *const Active_Balancing_Subsystem_M =
  &Active_Balancing_Subsystem_M_;

/* Exported data definition */

/* Definition for custom storage class: Global */
boolean_T SW_1;                        /* '<S1>/Active_Balancing_chart' */
boolean_T SW_2;                        /* '<S1>/Active_Balancing_chart' */
boolean_T SW_3;                        /* '<S1>/Active_Balancing_chart' */
boolean_T SW_4;                        /* '<S1>/Active_Balancing_chart' */
real32_T Voltage_cell_1;               /* '<Root>/Voltage_cell_1' */
real32_T Voltage_cell_2;               /* '<Root>/Voltage_cell_2' */

/* Forward declaration for local functions */
static void Active_Balancing_S_Need_Balance(void);
static void Active_Balancing_Lowest_Battery(void);
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Active_Balancing_Subsystem_M->Timing.TaskCounters.TID[1])++;
  if ((Active_Balancing_Subsystem_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [1.0s, 0.0s] */
    Active_Balancing_Subsystem_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for Chart: '<S1>/Active_Balancing_chart' */
static void Active_Balancing_S_Need_Balance(void)
{
  /* Inport: '<Root>/Voltage_cell_1' incorporates:
   *  Inport: '<Root>/Voltage_cell_2'
   */
  Active_Balancing_Subsystem_DW.Need_Balance_State = !(Voltage_cell_1 ==
    Voltage_cell_2);
}

/* Function for Chart: '<S1>/Active_Balancing_chart' */
static void Active_Balancing_Lowest_Battery(void)
{
  /* Inport: '<Root>/Voltage_cell_1' incorporates:
   *  Inport: '<Root>/Voltage_cell_2'
   */
  if (Voltage_cell_1 > Voltage_cell_2) {
    Active_Balancing_Subsystem_DW.lowest = 2.0;
  } else {
    Active_Balancing_Subsystem_DW.lowest = (Voltage_cell_2 > Voltage_cell_1);
  }

  /* End of Inport: '<Root>/Voltage_cell_1' */
}

/* Model step function */
void Active_Balancing_Subsystem_step(void)
{
  uint32_T elapsedTicks;
  if (Active_Balancing_Subsystem_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (fcncallgen): '<Root>/Call_100ms' incorporates:
     *  SubSystem: '<Root>/Active_Balancing_Subsystem'
     */
    /* Chart: '<S1>/Active_Balancing_chart' incorporates:
     *  Inport: '<Root>/Voltage_cell_1'
     *  Inport: '<Root>/Voltage_cell_2'
     */
    elapsedTicks = Active_Balancing_Subsystem_M->Timing.clockTick1 -
      Active_Balancing_Subsystem_DW.previousTicks;
    Active_Balancing_Subsystem_DW.previousTicks =
      Active_Balancing_Subsystem_M->Timing.clockTick1;
    if (Active_Balancing_Subsystem_DW.temporalCounter_i1 + elapsedTicks <= 1U) {
      Active_Balancing_Subsystem_DW.temporalCounter_i1 = (uint8_T)
        (Active_Balancing_Subsystem_DW.temporalCounter_i1 + elapsedTicks);
    } else {
      Active_Balancing_Subsystem_DW.temporalCounter_i1 = 1U;
    }

    if (Active_Balancing_Subsystem_DW.is_active_c3_Active_Balancing_S == 0U) {
      Active_Balancing_Subsystem_DW.is_active_c3_Active_Balancing_S = 1U;
      Active_Balancing_Subsystem_DW.is_Decision_Maker =
        Active_Balancin_IN_Leader_State;
      Active_Balancing_Subsystem_DW.Delta = fabsf(Voltage_cell_1 -
        Voltage_cell_2);
      Active_Balancing_S_Need_Balance();
      Active_Balancing_Lowest_Battery();
    } else if (Active_Balancing_Subsystem_DW.is_Decision_Maker ==
               Active_Balancin_IN_Leader_State) {
      if ((Active_Balancing_Subsystem_DW.Need_Balance_State == 1.0) &&
          (Active_Balancing_Subsystem_DW.Delta > Active_Balancing_S_Target_Delta)
          && (Active_Balancing_Subsystem_DW.lowest == 2.0)) {
        Active_Balancing_Subsystem_DW.is_Decision_Maker =
          Active_Balancin_IN_SW_Managment;
        Active_Balancing_Subsystem_DW.is_SW_Managment =
          Active_Balancing_Subs_IN_Mode_A;
        Active_Balancing_Subsystem_DW.temporalCounter_i1 = 0U;
        SW_1 = true;
        SW_3 = true;
      } else if ((Active_Balancing_Subsystem_DW.Need_Balance_State == 1.0) &&
                 (Active_Balancing_Subsystem_DW.Delta >
                  Active_Balancing_S_Target_Delta) &&
                 (Active_Balancing_Subsystem_DW.lowest == 1.0)) {
        Active_Balancing_Subsystem_DW.is_Decision_Maker =
          Active_Balancin_IN_SW_Managment;
        Active_Balancing_Subsystem_DW.is_SW_Managment =
          Active_Balancing_Subs_IN_Mode_B;
        Active_Balancing_Subsystem_DW.temporalCounter_i1 = 0U;
        SW_2 = true;
        SW_4 = true;
      } else {
        Active_Balancing_Subsystem_DW.Delta = fabsf(Voltage_cell_1 -
          Voltage_cell_2);
        Active_Balancing_S_Need_Balance();
        Active_Balancing_Lowest_Battery();
      }
    } else {
      /* case IN_SW_Managment: */
      if (Voltage_cell_1 == Voltage_cell_2) {
        switch (Active_Balancing_Subsystem_DW.is_SW_Managment) {
         case Active_Balancing_Subs_IN_Mode_A:
          SW_1 = false;
          SW_3 = false;
          Active_Balancing_Subsystem_DW.is_SW_Managment =
            Active_Balan_IN_NO_ACTIVE_CHILD;
          break;

         case Active_Balancing_Subs_IN_Mode_B:
          SW_2 = false;
          SW_4 = false;
          Active_Balancing_Subsystem_DW.is_SW_Managment =
            Active_Balan_IN_NO_ACTIVE_CHILD;
          break;
        }

        Active_Balancing_Subsystem_DW.is_Decision_Maker =
          Active_Balancin_IN_Leader_State;
        Active_Balancing_Subsystem_DW.Delta = fabsf(Voltage_cell_1 -
          Voltage_cell_2);
        Active_Balancing_S_Need_Balance();
        Active_Balancing_Lowest_Battery();
      } else if (Active_Balancing_Subsystem_DW.is_SW_Managment ==
                 Active_Balancing_Subs_IN_Mode_A) {
        if (Active_Balancing_Subsystem_DW.temporalCounter_i1 >= 1U) {
          SW_1 = false;
          SW_3 = false;
          Active_Balancing_Subsystem_DW.is_SW_Managment =
            Active_Balancing_Subs_IN_Mode_B;
          Active_Balancing_Subsystem_DW.temporalCounter_i1 = 0U;
          SW_2 = true;
          SW_4 = true;
        } else {
          Active_Balancing_S_Need_Balance();
          Active_Balancing_Subsystem_DW.Delta = fabsf(Voltage_cell_1 -
            Voltage_cell_2);
        }
      } else {
        /* case IN_Mode_B: */
        if (Active_Balancing_Subsystem_DW.temporalCounter_i1 >= 1U) {
          SW_2 = false;
          SW_4 = false;
          Active_Balancing_Subsystem_DW.is_SW_Managment =
            Active_Balancing_Subs_IN_Mode_A;
          Active_Balancing_Subsystem_DW.temporalCounter_i1 = 0U;
          SW_1 = true;
          SW_3 = true;
        } else {
          Active_Balancing_S_Need_Balance();
          Active_Balancing_Subsystem_DW.Delta = fabsf(Voltage_cell_1 -
            Voltage_cell_2);
        }
      }
    }

    /* End of Chart: '<S1>/Active_Balancing_chart' */
    /* End of Outputs for S-Function (fcncallgen): '<Root>/Call_100ms' */
  }

  if (Active_Balancing_Subsystem_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Active_Balancing_Subsystem_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void Active_Balancing_Subsystem_initialize(void)
{
  /* Enable for S-Function (fcncallgen): '<Root>/Call_100ms' incorporates:
   *  SubSystem: '<Root>/Active_Balancing_Subsystem'
   */
  /* Enable for Chart: '<S1>/Active_Balancing_chart' */
  Active_Balancing_Subsystem_DW.previousTicks =
    Active_Balancing_Subsystem_M->Timing.clockTick1;

  /* End of Enable for S-Function (fcncallgen): '<Root>/Call_100ms' */
}

/* Model terminate function */
void Active_Balancing_Subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
