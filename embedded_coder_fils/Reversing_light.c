/*
 * File: Reversing_light.c
 *
 * Code generated for Simulink model 'Reversing_light'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Mar  6 01:02:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Reversing_light.h"
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta);
extern uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta);
static void MATLABFunction(real_T rtu_u, real_T *rty_on, real_T *rty_reset,
  real_T *rty_off);

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabC_dgu(codertarget_arduinobase_block_d *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_blocks_ *obj);
static void rate_monotonic_scheduler(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Reversing_light_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(rtM, 1));
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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  rtM->Timing.RateInteraction.TID0_1 = (rtM->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
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
 *    '<S7>/MATLAB Function'
 *    '<S7>/MATLAB Function2'
 */
static void MATLABFunction(real_T rtu_u, real_T *rty_on, real_T *rty_reset,
  real_T *rty_off)
{
  if (rt_remd_snf(rtu_u, 2.0) == 0.0) {
    *rty_on = 0.0;
    *rty_reset = 1.0;
    *rty_off = 1.0;
  } else {
    *rty_on = 1.0;
    *rty_reset = 0.0;
    *rty_off = 0.0;
  }
}

uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int16_T curState;
  int16_T newState;
  int16_T newStateR;
  int16_T lastzcevent;
  uint32_T previousState;

  /* S-Function (sdspcount2): '<S7>/Counter' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0UL;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt > 0.0) {
    curState = 2;
  } else {
    curState = !(evt < 0.0);
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

  /* End of S-Function (sdspcount2): '<S7>/Counter' */
  return retVal;
}

uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int16_T curState;
  int16_T newState;
  int16_T newStateR;
  int16_T lastzcevent;
  uint32_T previousState;

  /* S-Function (sdspcount2): '<S7>/Counter' */
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

  /* End of S-Function (sdspcount2): '<S7>/Counter' */
  return retVal;
}

static void matlabCodegenHandle_matlabC_dgu(codertarget_arduinobase_block_d *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_blocks_ *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function for TID0 */
void Reversing_light_step0(void)       /* Sample time: [0.001s, 0.0s] */
{
  int16_T rtb_PulseGenerator;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition generated from: '<S1>/AND' */
  if (rtM->Timing.RateInteraction.TID0_1) {
    rtDW.TmpRTBAtANDInport1 = rtDW.TmpRTBAtANDInport1_Buffer0;
  }

  /* End of RateTransition generated from: '<S1>/AND' */

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  rtb_PulseGenerator = ((rtDW.clockTickCounter < 125L) && (rtDW.clockTickCounter
    >= 0L));
  if (rtDW.clockTickCounter >= 249L) {
    rtDW.clockTickCounter = 0L;
  } else {
    rtDW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Logic: '<S1>/AND'
   */
  writeDigitalPin(9, (uint8_T)(rtDW.TmpRTBAtANDInport1 && (rtb_PulseGenerator !=
    0)));

  /* RateTransition generated from: '<S2>/AND' */
  if (rtM->Timing.RateInteraction.TID0_1) {
    rtDW.TmpRTBAtANDInport1_m = rtDW.TmpRTBAtANDInport1_Buffer0_h;
  }

  /* End of RateTransition generated from: '<S2>/AND' */

  /* DiscretePulseGenerator: '<S2>/Pulse Generator' */
  rtb_PulseGenerator = ((rtDW.clockTickCounter_j < 125L) &&
                        (rtDW.clockTickCounter_j >= 0L));
  if (rtDW.clockTickCounter_j >= 249L) {
    rtDW.clockTickCounter_j = 0L;
  } else {
    rtDW.clockTickCounter_j++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Logic: '<S2>/AND'
   */
  writeDigitalPin(10, (uint8_T)(rtDW.TmpRTBAtANDInport1_m && (rtb_PulseGenerator
    != 0)));
}

/* Model step function for TID1 */
void Reversing_light_step1(void)       /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_reset_c;
  real_T rtb_Counter;
  boolean_T rtb_Compare;
  boolean_T rtb_OR_e;
  boolean_T rtb_OR_h;
  boolean_T rtb_NOT;
  real_T Merge;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (rtDW.obj.SampleTime != 0.01) {
    rtDW.obj.SampleTime = 0.01;
  }

  rtb_Compare = readDigitalPin(2);

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (rtDW.obj_h.SampleTime != 0.01) {
    rtDW.obj_h.SampleTime = 0.01;
  }

  rtb_OR_e = readDigitalPin(3);

  /* MATLABSystem: '<Root>/Digital Input2' */
  if (rtDW.obj_b.SampleTime != 0.01) {
    rtDW.obj_b.SampleTime = 0.01;
  }

  rtb_NOT = readDigitalPin(4);

  /* Delay: '<S7>/Delay' */
  rtDW.Delay = rtDW.Delay_DSTATE[0];

  /* S-Function (sdspcount2): '<S7>/Counter' incorporates:
   *  MATLABSystem: '<Root>/Digital Input'
   */
  if (MWDSP_EPH_R_D(rtDW.Delay, &rtDW.Counter_RstEphState) != 0UL) {
    rtDW.Counter_Count = 1U;
  }

  if (MWDSP_EPH_R_B(rtb_Compare, &rtDW.Counter_ClkEphState) != 0UL) {
    if (rtDW.Counter_Count < 255) {
      rtDW.Counter_Count++;
    } else {
      rtDW.Counter_Count = 0U;
    }
  }

  /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
   *  S-Function (sdspcount2): '<S7>/Counter'
   */
  MATLABFunction((real_T)rtDW.Counter_Count, &Merge, &rtb_reset_c, &Merge);

  /* S-Function (sdspcount2): '<S3>/Counter' incorporates:
   *  MATLABSystem: '<Root>/Digital Input2'
   */
  if (MWDSP_EPH_R_B(rtb_NOT, &rtDW.Counter_ClkEphState_l) != 0UL) {
    if (rtDW.Counter_Count_g < 255) {
      rtDW.Counter_Count_g++;
    } else {
      rtDW.Counter_Count_g = 0U;
    }
  }

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  S-Function (sdspcount2): '<S3>/Counter'
   */
  if (rt_remd_snf((real_T)rtDW.Counter_Count_g, 2.0) == 0.0) {
    rtb_Counter = 1.0;
  } else {
    rtb_Counter = 0.0;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  rtb_Compare = (rtb_Counter == 0.0);

  /* Logic: '<S6>/NOT' */
  rtb_NOT = !rtb_Compare;

  /* Logic: '<S1>/OR' */
  rtb_OR_h = ((Merge != 0.0) || rtb_NOT);

  /* RateTransition generated from: '<S1>/AND' */
  rtDW.TmpRTBAtANDInport1_Buffer0 = rtb_OR_h;

  /* Delay: '<S7>/Delay1' */
  rtDW.Delay1 = rtDW.Delay1_DSTATE[0];

  /* S-Function (sdspcount2): '<S7>/Counter1' incorporates:
   *  MATLABSystem: '<Root>/Digital Input1'
   */
  if (MWDSP_EPH_R_D(rtDW.Delay1, &rtDW.Counter1_RstEphState) != 0UL) {
    rtDW.Counter1_Count = 1U;
  }

  if (MWDSP_EPH_R_B(rtb_OR_e, &rtDW.Counter1_ClkEphState) != 0UL) {
    if (rtDW.Counter1_Count < 255) {
      rtDW.Counter1_Count++;
    } else {
      rtDW.Counter1_Count = 0U;
    }
  }

  /* MATLAB Function: '<S7>/MATLAB Function2' incorporates:
   *  S-Function (sdspcount2): '<S7>/Counter1'
   */
  MATLABFunction((real_T)rtDW.Counter1_Count, &Merge, &rtb_Counter, &Merge);

  /* Logic: '<S2>/OR' */
  rtb_OR_e = ((Merge != 0.0) || rtb_NOT);

  /* RateTransition generated from: '<S2>/AND' */
  rtDW.TmpRTBAtANDInport1_Buffer0_h = rtb_OR_e;

  /* RateTransition generated from: '<S4>/AND' */
  rtDW.TmpRTBAtANDInport2_Buffer0 = rtb_Compare;

  /* RateTransition generated from: '<S5>/AND' */
  rtDW.TmpRTBAtANDInport2_Buffer0_o = rtb_Compare;

  /* Update for Delay: '<S7>/Delay' */
  rtDW.Delay_DSTATE[0] = rtDW.Delay_DSTATE[1];
  rtDW.Delay_DSTATE[1] = rtb_Counter;

  /* Update for Delay: '<S7>/Delay1' */
  rtDW.Delay1_DSTATE[0] = rtDW.Delay1_DSTATE[1];
  rtDW.Delay1_DSTATE[1] = rtb_reset_c;
}

/* Model initialize function */
void Reversing_light_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for S-Function (sdspcount2): '<S7>/Counter' */
  rtDW.Counter_ClkEphState = 5UL;
  rtDW.Counter_RstEphState = 5UL;
  rtDW.Counter_Count = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S3>/Counter' */
  rtDW.Counter_ClkEphState_l = 5UL;
  rtDW.Counter_Count_g = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S7>/Counter1' */
  rtDW.Counter1_ClkEphState = 5UL;
  rtDW.Counter1_RstEphState = 5UL;
  rtDW.Counter1_Count = 1U;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  rtDW.obj_h5.matlabCodegenIsDeleted = false;
  rtDW.obj_h5.isInitialized = 1L;
  digitalIOSetup(9, 1);
  rtDW.obj_h5.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  rtDW.obj_g.matlabCodegenIsDeleted = false;
  rtDW.obj_g.isInitialized = 1L;
  digitalIOSetup(10, 1);
  rtDW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  rtDW.obj.matlabCodegenIsDeleted = false;
  rtDW.obj.SampleTime = 0.01;
  rtDW.obj.isInitialized = 1L;
  digitalIOSetup(2, 0);
  rtDW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  rtDW.obj_h.matlabCodegenIsDeleted = false;
  rtDW.obj_h.SampleTime = 0.01;
  rtDW.obj_h.isInitialized = 1L;
  digitalIOSetup(3, 0);
  rtDW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input2' */
  rtDW.obj_b.matlabCodegenIsDeleted = false;
  rtDW.obj_b.SampleTime = 0.01;
  rtDW.obj_b.isInitialized = 1L;
  digitalIOSetup(4, 0);
  rtDW.obj_b.isSetupComplete = true;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
