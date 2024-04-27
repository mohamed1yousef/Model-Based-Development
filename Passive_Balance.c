/*
 * File: Passive_Balance.c
 *
 * Code generated for Simulink model 'Passive_Balance'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Apr 27 20:27:26 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Passive_Balance.h"
#include "Passive_Balance_private.h"

/* Named constants for Chart: '<S1>/Passive_Balance_Chart' */
#define Passive_Bala_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Passive_Balance_IN_All_Balanced ((uint8_T)1U)
#define Passive_Balance_IN_Mange_Sw    ((uint8_T)2U)
#define Passive_Balance_IN_Mode_A      ((uint8_T)1U)
#define Passive_Balance_IN_Mode_B      ((uint8_T)2U)
#define Passive_Balance_IN_Mode_C      ((uint8_T)3U)

/* Block states (default storage) */
DW_Passive_Balance_T Passive_Balance_DW;

/* Real-time model */
RT_MODEL_Passive_Balance_T Passive_Balance_M_;
RT_MODEL_Passive_Balance_T *const Passive_Balance_M = &Passive_Balance_M_;

/* Exported data definition */

/* Definition for custom storage class: Global */
boolean_T Cell1_Sw;                    /* '<S1>/Passive_Balance_Chart' */
boolean_T Cell2_Sw;                    /* '<S1>/Passive_Balance_Chart' */
boolean_T Cell3_Sw;                    /* '<S1>/Passive_Balance_Chart' */
real32_T Voltage_cell_1;               /* '<Root>/Voltage_cell_1' */
real32_T Voltage_cell_2;               /* '<Root>/Voltage_cell_2' */
real32_T Voltage_cell_3;               /* '<Root>/Voltage_cell_3' */

/* Forward declaration for local functions */
static void Passive_Balance_Need_No_Balance(void);
static void Passive_Balance_equality(void);
static void Passive_Balance_State_Cell1(void);
static void Passive_Balance_State_Cell2(void);
static void Passive_Balance_State_Cell3(void);

/* Function for Chart: '<S1>/Passive_Balance_Chart' */
static void Passive_Balance_Need_No_Balance(void)
{
  /* Inport: '<Root>/Voltage_cell_1' incorporates:
   *  Inport: '<Root>/Voltage_cell_2'
   *  Inport: '<Root>/Voltage_cell_3'
   */
  Passive_Balance_DW.state = ((Voltage_cell_1 == Voltage_cell_2) &&
    (Voltage_cell_1 == Voltage_cell_3));
}

/* Function for Chart: '<S1>/Passive_Balance_Chart' */
static void Passive_Balance_equality(void)
{
  if (Passive_Balance_DW.Lowest_B == 1.0) {
    /* Inport: '<Root>/Voltage_cell_1' incorporates:
     *  Inport: '<Root>/Voltage_cell_3'
     */
    if (Voltage_cell_1 == Voltage_cell_3) {
      Cell3_Sw = false;
    } else {
      /* Inport: '<Root>/Voltage_cell_2' */
      Cell2_Sw = ((!(Voltage_cell_2 == Voltage_cell_1)) && Cell2_Sw);
    }
  } else if (Passive_Balance_DW.Lowest_B == 3.0) {
    /* Inport: '<Root>/Voltage_cell_1' incorporates:
     *  Inport: '<Root>/Voltage_cell_3'
     */
    if (Voltage_cell_1 == Voltage_cell_3) {
      Cell1_Sw = false;
    } else {
      /* Inport: '<Root>/Voltage_cell_2' */
      Cell2_Sw = ((!(Voltage_cell_2 == Voltage_cell_3)) && Cell2_Sw);
    }
  } else {
    if (Passive_Balance_DW.Lowest_B == 2.0) {
      /* Inport: '<Root>/Voltage_cell_1' incorporates:
       *  Inport: '<Root>/Voltage_cell_2'
       */
      if (Voltage_cell_1 == Voltage_cell_2) {
        Cell1_Sw = false;
      } else {
        /* Inport: '<Root>/Voltage_cell_3' */
        Cell3_Sw = ((!(Voltage_cell_2 == Voltage_cell_3)) && Cell3_Sw);
      }
    }
  }
}

/* Function for Chart: '<S1>/Passive_Balance_Chart' */
static void Passive_Balance_State_Cell1(void)
{
  /* Inport: '<Root>/Voltage_cell_1' incorporates:
   *  Inport: '<Root>/Voltage_cell_2'
   *  Inport: '<Root>/Voltage_cell_3'
   */
  if ((Voltage_cell_1 >= Voltage_cell_2) >= Voltage_cell_3) {
    if (Voltage_cell_2 >= Voltage_cell_3) {
      Passive_Balance_DW.Lowest_B = 3.0;
    } else {
      if (Voltage_cell_3 >= Voltage_cell_2) {
        Passive_Balance_DW.Lowest_B = 2.0;
      }
    }
  }

  /* End of Inport: '<Root>/Voltage_cell_1' */
}

/* Function for Chart: '<S1>/Passive_Balance_Chart' */
static void Passive_Balance_State_Cell2(void)
{
  /* Inport: '<Root>/Voltage_cell_2' incorporates:
   *  Inport: '<Root>/Voltage_cell_1'
   *  Inport: '<Root>/Voltage_cell_3'
   */
  if ((Voltage_cell_2 >= Voltage_cell_1) >= Voltage_cell_3) {
    if (Voltage_cell_1 >= Voltage_cell_3) {
      Passive_Balance_DW.Lowest_B = 3.0;
    } else {
      if (Voltage_cell_3 >= Voltage_cell_1) {
        Passive_Balance_DW.Lowest_B = 1.0;
      }
    }
  }

  /* End of Inport: '<Root>/Voltage_cell_2' */
}

/* Function for Chart: '<S1>/Passive_Balance_Chart' */
static void Passive_Balance_State_Cell3(void)
{
  /* Inport: '<Root>/Voltage_cell_3' incorporates:
   *  Inport: '<Root>/Voltage_cell_1'
   *  Inport: '<Root>/Voltage_cell_2'
   */
  if ((Voltage_cell_3 >= Voltage_cell_1) >= Voltage_cell_2) {
    if (Voltage_cell_1 >= Voltage_cell_2) {
      Passive_Balance_DW.Lowest_B = 2.0;
    } else {
      if (Voltage_cell_2 >= Voltage_cell_1) {
        Passive_Balance_DW.Lowest_B = 1.0;
      }
    }
  }

  /* End of Inport: '<Root>/Voltage_cell_3' */
}

/* Model step function */
void Passive_Balance_step(void)
{
  boolean_T guard1 = false;

  /* S-Function (fcncallgen): '<Root>/call_100ms' incorporates:
   *  SubSystem: '<Root>/Passive_Balance_System'
   */
  /* Chart: '<S1>/Passive_Balance_Chart' */
  if (Passive_Balance_DW.is_active_c1_Passive_Balance == 0U) {
    Passive_Balance_DW.is_active_c1_Passive_Balance = 1U;
    Passive_Balance_DW.is_Balancer = Passive_Balance_IN_All_Balanced;
    Passive_Balance_Need_No_Balance();
  } else if (Passive_Balance_DW.is_Balancer == Passive_Balance_IN_All_Balanced)
  {
    guard1 = false;
    if (Passive_Balance_DW.state == 0.0) {
      if (Passive_Balance_DW.Lowest_B == 1.0) {
        Passive_Balance_DW.is_Balancer = Passive_Balance_IN_Mange_Sw;
        Passive_Balance_DW.is_Mange_Sw = Passive_Balance_IN_Mode_A;
        Cell2_Sw = true;
        Cell3_Sw = true;
      } else if (Passive_Balance_DW.Lowest_B == 3.0) {
        Passive_Balance_DW.is_Balancer = Passive_Balance_IN_Mange_Sw;
        Passive_Balance_DW.is_Mange_Sw = Passive_Balance_IN_Mode_B;
        Cell2_Sw = true;
        Cell1_Sw = true;
      } else if (Passive_Balance_DW.Lowest_B == 2.0) {
        Passive_Balance_DW.is_Balancer = Passive_Balance_IN_Mange_Sw;
        Passive_Balance_DW.is_Mange_Sw = Passive_Balance_IN_Mode_C;
        Cell1_Sw = true;
        Cell3_Sw = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      Passive_Balance_Need_No_Balance();
      Passive_Balance_State_Cell1();
      Passive_Balance_State_Cell2();
      Passive_Balance_State_Cell3();
    }
  } else {
    /* case IN_Mange_Sw: */
    if (Passive_Balance_DW.state == 1.0) {
      switch (Passive_Balance_DW.is_Mange_Sw) {
       case Passive_Balance_IN_Mode_A:
        Cell2_Sw = true;
        Cell3_Sw = true;
        Passive_Balance_DW.is_Mange_Sw = Passive_Bala_IN_NO_ACTIVE_CHILD;
        break;

       case Passive_Balance_IN_Mode_B:
        Cell2_Sw = false;
        Cell1_Sw = false;
        Passive_Balance_DW.is_Mange_Sw = Passive_Bala_IN_NO_ACTIVE_CHILD;
        break;

       case Passive_Balance_IN_Mode_C:
        Cell1_Sw = true;
        Cell3_Sw = true;
        Passive_Balance_DW.is_Mange_Sw = Passive_Bala_IN_NO_ACTIVE_CHILD;
        break;
      }

      Passive_Balance_DW.is_Balancer = Passive_Balance_IN_All_Balanced;
      Passive_Balance_Need_No_Balance();
    } else {
      switch (Passive_Balance_DW.is_Mange_Sw) {
       case Passive_Balance_IN_Mode_A:
        Passive_Balance_Need_No_Balance();
        Passive_Balance_equality();
        break;

       case Passive_Balance_IN_Mode_B:
        Passive_Balance_Need_No_Balance();
        Passive_Balance_equality();
        break;

       default:
        /* case IN_Mode_C: */
        Passive_Balance_Need_No_Balance();
        Passive_Balance_equality();
        break;
      }
    }
  }

  /* End of Chart: '<S1>/Passive_Balance_Chart' */
  /* End of Outputs for S-Function (fcncallgen): '<Root>/call_100ms' */
}

/* Model initialize function */
void Passive_Balance_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Passive_Balance_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
