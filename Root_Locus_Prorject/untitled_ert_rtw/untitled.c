/*
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Mar 13 17:18:53 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void untitled_SystemCore_release_b(codertarget_arduinobase_inter_T *obj);
static void untitled_SystemCore_delete_b(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCod_b(codertarget_arduinobase_inter_T *obj);
static void untitled_SystemCore_release(codertarget_arduinobase_int_b_T *obj);
static void untitled_SystemCore_delete(codertarget_arduinobase_int_b_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_b_T *obj);
static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_int_b_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0);
static void untitled_SystemCore_release_b(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
    MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
  }
}

static void untitled_SystemCore_delete_b(codertarget_arduinobase_inter_T *obj)
{
  untitled_SystemCore_release_b(obj);
}

static void matlabCodegenHandle_matlabCod_b(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    untitled_SystemCore_delete_b(obj);
  }
}

static void untitled_SystemCore_release(codertarget_arduinobase_int_b_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void untitled_SystemCore_delete(codertarget_arduinobase_int_b_T *obj)
{
  untitled_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_b_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    untitled_SystemCore_delete(obj);
  }
}

static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_int_b_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0)
{
  iobj_0->AvailablePwmPinNames.f1 = '2';
  iobj_0->AvailablePwmPinNames.f2 = '3';
  iobj_0->AvailablePwmPinNames.f3 = '4';
  iobj_0->AvailablePwmPinNames.f4 = '5';
  iobj_0->AvailablePwmPinNames.f5 = '6';
  iobj_0->AvailablePwmPinNames.f6 = '7';
  iobj_0->AvailablePwmPinNames.f7 = '8';
  iobj_0->AvailablePwmPinNames.f8 = '9';
  iobj_0->AvailablePwmPinNames.f9[0] = '1';
  iobj_0->AvailablePwmPinNames.f9[1] = '0';
  iobj_0->AvailablePwmPinNames.f10[0] = '1';
  iobj_0->AvailablePwmPinNames.f10[1] = '1';
  iobj_0->AvailablePwmPinNames.f11[0] = '1';
  iobj_0->AvailablePwmPinNames.f11[1] = '2';
  iobj_0->AvailablePwmPinNames.f12[0] = '1';
  iobj_0->AvailablePwmPinNames.f12[1] = '3';
  obj->Hw = iobj_0;
  obj->PinPWM = 5UL;
}

/* Model step function */
void untitled_step(void)
{
  uint16_T rtb_AnalogInput_0;
  codertarget_arduinobase_inter_T *obj;
  codertarget_arduinobase_int_b_T *obj_0;
  real_T u0;

  /* Step: '<Root>/Step' */
  if (untitled_M->Timing.t[0] < untitled_P.Step_Time) {
    untitled_B.Step = untitled_P.Step_Y0;
  } else {
    untitled_B.Step = untitled_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* MATLABSystem: '<Root>/Analog Input' */
  if (untitled_DW.obj_p.SampleTime != untitled_P.AnalogInput_SampleTime) {
    untitled_DW.obj_p.SampleTime = untitled_P.AnalogInput_SampleTime;
  }

  obj = &untitled_DW.obj_p;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (untitled_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_AnalogInput_0,
     3);

  /* Gain: '<Root>/Gain2' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   */
  untitled_B.Gain2 = (uint32_T)untitled_P.Gain2_Gain * rtb_AnalogInput_0;

  /* MATLABSystem: '<Root>/PWM' */
  obj_0 = &untitled_DW.obj;
  obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(untitled_DW.obj.PinPWM);

  /* Gain: '<Root>/Gain1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum'
   */
  u0 = (untitled_B.Step - (real_T)untitled_B.Gain2 * 1.1920928955078125E-7) *
    untitled_P.Gain_Gain * untitled_P.Gain1_Gain;

  /* MATLABSystem: '<Root>/PWM' */
  if (!(u0 < 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 > 0.0)) {
    u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(untitled_DW.obj.MW_PWM_HANDLE, u0);

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)untitled_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(1, (real_T)((untitled_M->Timing.clockTick1) * 0.01));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.t[0]) >
          untitled_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.t[0] =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    untitled_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&untitled_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  rtmSetTFinal(untitled_M, 10.0);
  untitled_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (1135589620U);
  untitled_M->Sizes.checksums[1] = (806087969U);
  untitled_M->Sizes.checksums[2] = (3546250213U);
  untitled_M->Sizes.checksums[3] = (27383278U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_inter_T *obj;
    codertarget_arduinobase_int_b_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    untitled_DW.obj_p.matlabCodegenIsDeleted = true;
    untitled_DW.obj_p.isInitialized = 0L;
    untitled_DW.obj_p.SampleTime = -1.0;
    untitled_DW.obj_p.matlabCodegenIsDeleted = false;
    untitled_DW.obj_p.SampleTime = untitled_P.AnalogInput_SampleTime;
    obj = &untitled_DW.obj_p;
    untitled_DW.obj_p.isSetupComplete = false;
    untitled_DW.obj_p.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    untitled_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    untitled_DW.obj.isInitialized = 0L;
    untitled_DW.obj.matlabCodegenIsDeleted = false;
    arduino_PWMOutput_set_pinNumber(&untitled_DW.obj, &untitled_DW.gobj_2);
    obj_0 = &untitled_DW.obj;
    untitled_DW.obj.isSetupComplete = false;
    untitled_DW.obj.isInitialized = 1L;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(untitled_DW.obj.PinPWM, 0.0, 0.0);
    obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(untitled_DW.obj.PinPWM);
    MW_PWM_Start(untitled_DW.obj.MW_PWM_HANDLE);
    untitled_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  matlabCodegenHandle_matlabCod_b(&untitled_DW.obj_p);

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
