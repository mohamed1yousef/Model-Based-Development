/*
 * File: Reversing_light.c
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
#include "Reversing_light_dt.h"

/* Block signals (default storage) */
B_Reversing_light_T Reversing_light_B;

/* Block states (default storage) */
DW_Reversing_light_T Reversing_light_DW;

/* Real-time model */
RT_MODEL_Reversing_light_T Reversing_light_M_;
RT_MODEL_Reversing_light_T *const Reversing_light_M = &Reversing_light_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabC_dgu(codertarget_arduinobase_blo_d_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Reversing_light_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Reversing_light_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Reversing_light_M->Timing.TaskCounters.TID[1])++;
  if ((Reversing_light_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    Reversing_light_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = fabs(u0 / u1);
      if (!(fabs(u1_0 - floor(u1_0 + 0.5)) > DBL_EPSILON * u1_0)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/*
 * Output and update for atomic system:
 *    '<S3>/MATLAB Function'
 *    '<S4>/MATLAB Function'
 *    '<S5>/MATLAB Function'
 */
void Reversing_li_MATLABFunction(real_T rtu_u, real_T *rty_on, real_T *rty_off)
{
  if (rt_remd_snf(rtu_u, 2.0) == 0.0) {
    *rty_on = 0.0;
    *rty_off = 1.0;
  } else {
    *rty_on = 1.0;
    *rty_off = 0.0;
  }
}

uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int16_T curState;
  int16_T newState;
  int16_T newStateR;
  int16_T lastzcevent;
  uint32_T previousState;

  /* S-Function (sdspcount2): '<S3>/Counter' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0UL;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt) {
    curState = 2;
  } else {
    curState = 1;
  }

  if (*sta == 5UL) {
    newStateR = curState;
  } else {
    if ((uint32_T)curState != *sta) {
      if (*sta == 3UL) {
        if ((uint16_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 2;
          previousState = 1UL;
        }
      }

      if (previousState == 4UL) {
        if ((uint16_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 3;
          previousState = 1UL;
        }
      }

      if ((previousState == 1UL) && ((uint16_T)curState == 2U)) {
        retVal = 2UL;
      }

      if (previousState == 0UL) {
        retVal = 2UL;
      }

      if ((uint16_T)retVal == (uint16_T)lastzcevent) {
        retVal = 0UL;
      }

      if (((uint16_T)curState == 1U) && ((uint16_T)retVal == 2U)) {
        newState = 3;
      } else {
        newState = curState;
      }
    }
  }

  if ((uint16_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0UL;
  }

  if ((uint16_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<S3>/Counter' */
  return retVal;
}

static void matlabCodegenHandle_matlabC_dgu(codertarget_arduinobase_blo_d_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function for TID0 */
void Reversing_light_step0(void)       /* Sample time: [0.001s, 0.0s] */
{
  real_T rtb_PulseGenerator;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  rtb_PulseGenerator = (Reversing_light_DW.clockTickCounter <
                        Reversing_light_P.PulseGenerator_Duty) &&
    (Reversing_light_DW.clockTickCounter >= 0L) ?
    Reversing_light_P.PulseGenerator_Amp : 0.0;
  if (Reversing_light_DW.clockTickCounter >=
      Reversing_light_P.PulseGenerator_Period - 1.0) {
    Reversing_light_DW.clockTickCounter = 0L;
  } else {
    Reversing_light_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Logic: '<S1>/AND'
   */
  writeDigitalPin(9, (uint8_T)(Reversing_light_B.OR && (rtb_PulseGenerator !=
    0.0)));

  /* DiscretePulseGenerator: '<S2>/Pulse Generator' */
  rtb_PulseGenerator = (Reversing_light_DW.clockTickCounter_j <
                        Reversing_light_P.PulseGenerator_Duty_m) &&
    (Reversing_light_DW.clockTickCounter_j >= 0L) ?
    Reversing_light_P.PulseGenerator_Amp_f : 0.0;
  if (Reversing_light_DW.clockTickCounter_j >=
      Reversing_light_P.PulseGenerator_Period_p - 1.0) {
    Reversing_light_DW.clockTickCounter_j = 0L;
  } else {
    Reversing_light_DW.clockTickCounter_j++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Logic: '<S2>/AND'
   */
  writeDigitalPin(10, (uint8_T)(Reversing_light_B.OR_i && (rtb_PulseGenerator !=
    0.0)));

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)Reversing_light_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(Reversing_light_M)!=-1) &&
        !((rtmGetTFinal(Reversing_light_M)-Reversing_light_M->Timing.taskTime0) >
          Reversing_light_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Reversing_light_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Reversing_light_M)) {
      rtmSetErrorStatus(Reversing_light_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Reversing_light_M->Timing.taskTime0 =
    ((time_T)(++Reversing_light_M->Timing.clockTick0)) *
    Reversing_light_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void Reversing_light_step1(void)       /* Sample time: [0.01s, 0.0s] */
{
  boolean_T rtb_DigitalInput1_0;
  boolean_T rtb_DigitalInput2_0;
  boolean_T rtb_NOT;
  real_T Merge_o;
  real_T Merge;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (Reversing_light_DW.obj.SampleTime !=
      Reversing_light_P.DigitalInput_SampleTime) {
    Reversing_light_DW.obj.SampleTime =
      Reversing_light_P.DigitalInput_SampleTime;
  }

  rtb_NOT = readDigitalPin(2);

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (Reversing_light_DW.obj_h.SampleTime !=
      Reversing_light_P.DigitalInput1_SampleTime) {
    Reversing_light_DW.obj_h.SampleTime =
      Reversing_light_P.DigitalInput1_SampleTime;
  }

  rtb_DigitalInput1_0 = readDigitalPin(3);

  /* MATLABSystem: '<Root>/Digital Input2' */
  if (Reversing_light_DW.obj_b.SampleTime !=
      Reversing_light_P.DigitalInput2_SampleTime) {
    Reversing_light_DW.obj_b.SampleTime =
      Reversing_light_P.DigitalInput2_SampleTime;
  }

  rtb_DigitalInput2_0 = readDigitalPin(4);

  /* S-Function (sdspcount2): '<S3>/Counter' incorporates:
   *  MATLABSystem: '<Root>/Digital Input'
   */
  if (MWDSP_EPH_R_B(rtb_NOT, &Reversing_light_DW.Counter_ClkEphState) != 0UL) {
    if (Reversing_light_DW.Counter_Count < 255) {
      Reversing_light_DW.Counter_Count++;
    } else {
      Reversing_light_DW.Counter_Count = 0U;
    }
  }

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  S-Function (sdspcount2): '<S3>/Counter'
   */
  Reversing_li_MATLABFunction((real_T)Reversing_light_DW.Counter_Count, &Merge,
    &Merge);

  /* S-Function (sdspcount2): '<S5>/Counter' incorporates:
   *  MATLABSystem: '<Root>/Digital Input2'
   */
  if (MWDSP_EPH_R_B(rtb_DigitalInput2_0,
                    &Reversing_light_DW.Counter_ClkEphState_l) != 0UL) {
    if (Reversing_light_DW.Counter_Count_g < 255) {
      Reversing_light_DW.Counter_Count_g++;
    } else {
      Reversing_light_DW.Counter_Count_g = 0U;
    }
  }

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  S-Function (sdspcount2): '<S5>/Counter'
   */
  Reversing_li_MATLABFunction((real_T)Reversing_light_DW.Counter_Count_g,
    &Merge_o, &Merge_o);

  /* Logic: '<S8>/NOT' incorporates:
   *  Constant: '<S12>/Constant'
   *  RelationalOperator: '<S12>/Compare'
   */
  rtb_NOT = !(Merge_o == Reversing_light_P.Constant_Value);

  /* Logic: '<S1>/OR' */
  Reversing_light_B.OR = ((Merge != 0.0) || rtb_NOT);

  /* S-Function (sdspcount2): '<S4>/Counter' incorporates:
   *  MATLABSystem: '<Root>/Digital Input1'
   */
  if (MWDSP_EPH_R_B(rtb_DigitalInput1_0,
                    &Reversing_light_DW.Counter_ClkEphState_k) != 0UL) {
    if (Reversing_light_DW.Counter_Count_o < 255) {
      Reversing_light_DW.Counter_Count_o++;
    } else {
      Reversing_light_DW.Counter_Count_o = 0U;
    }
  }

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  S-Function (sdspcount2): '<S4>/Counter'
   */
  Reversing_li_MATLABFunction((real_T)Reversing_light_DW.Counter_Count_o, &Merge,
    &Merge);

  /* Logic: '<S2>/OR' */
  Reversing_light_B.OR_i = ((Merge != 0.0) || rtb_NOT);
  rtExtModeUpload(1, (real_T)((Reversing_light_M->Timing.clockTick1) * 0.01));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Reversing_light_M->Timing.clockTick1++;
}

/* Model initialize function */
void Reversing_light_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Reversing_light_M, -1);
  Reversing_light_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Reversing_light_M->Sizes.checksums[0] = (2376804126U);
  Reversing_light_M->Sizes.checksums[1] = (656871597U);
  Reversing_light_M->Sizes.checksums[2] = (1140106463U);
  Reversing_light_M->Sizes.checksums[3] = (63821871U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    Reversing_light_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Reversing_light_M->extModeInfo,
      &Reversing_light_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Reversing_light_M->extModeInfo,
                        Reversing_light_M->Sizes.checksums);
    rteiSetTPtr(Reversing_light_M->extModeInfo, rtmGetTPtr(Reversing_light_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Reversing_light_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* InitializeConditions for S-Function (sdspcount2): '<S3>/Counter' */
  Reversing_light_DW.Counter_ClkEphState = 5UL;
  Reversing_light_DW.Counter_Count = Reversing_light_P.Counter_InitialCount;

  /* InitializeConditions for S-Function (sdspcount2): '<S5>/Counter' */
  Reversing_light_DW.Counter_ClkEphState_l = 5UL;
  Reversing_light_DW.Counter_Count_g = Reversing_light_P.Counter_InitialCount_l;

  /* InitializeConditions for S-Function (sdspcount2): '<S4>/Counter' */
  Reversing_light_DW.Counter_ClkEphState_k = 5UL;
  Reversing_light_DW.Counter_Count_o = Reversing_light_P.Counter_InitialCount_n;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  Reversing_light_DW.obj_h5.matlabCodegenIsDeleted = false;
  Reversing_light_DW.obj_h5.isInitialized = 1L;
  digitalIOSetup(9, 1);
  Reversing_light_DW.obj_h5.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  Reversing_light_DW.obj_g.matlabCodegenIsDeleted = false;
  Reversing_light_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(10, 1);
  Reversing_light_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  Reversing_light_DW.obj.matlabCodegenIsDeleted = false;
  Reversing_light_DW.obj.SampleTime = Reversing_light_P.DigitalInput_SampleTime;
  Reversing_light_DW.obj.isInitialized = 1L;
  digitalIOSetup(2, 0);
  Reversing_light_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  Reversing_light_DW.obj_h.matlabCodegenIsDeleted = false;
  Reversing_light_DW.obj_h.SampleTime =
    Reversing_light_P.DigitalInput1_SampleTime;
  Reversing_light_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(3, 0);
  Reversing_light_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input2' */
  Reversing_light_DW.obj_b.matlabCodegenIsDeleted = false;
  Reversing_light_DW.obj_b.SampleTime =
    Reversing_light_P.DigitalInput2_SampleTime;
  Reversing_light_DW.obj_b.isInitialized = 1L;
  digitalIOSetup(4, 0);
  Reversing_light_DW.obj_b.isSetupComplete = true;
}

/* Model terminate function */
void Reversing_light_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  matlabCodegenHandle_matlabC_dgu(&Reversing_light_DW.obj_h5);

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  matlabCodegenHandle_matlabC_dgu(&Reversing_light_DW.obj_g);

  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  matlabCodegenHandle_matlabCodeg(&Reversing_light_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  matlabCodegenHandle_matlabCodeg(&Reversing_light_DW.obj_h);

  /* Terminate for MATLABSystem: '<Root>/Digital Input2' */
  matlabCodegenHandle_matlabCodeg(&Reversing_light_DW.obj_b);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
