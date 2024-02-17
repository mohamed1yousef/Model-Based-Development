/*
 * File: Temperature_Control_System0.h
 *
 * Code generated for Simulink model 'Temperature_Control_System0'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Feb 17 22:10:44 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (8-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Temperature_Control_System0_h_
#define RTW_HEADER_Temperature_Control_System0_h_
#include <string.h>
#ifndef Temperature_Control_System0_COMMON_INCLUDES_
# define Temperature_Control_System0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                        /* Temperature_Control_System0_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T uthetimeconstantofthesystem;
                               /* '<S1>/1// the time constant of the system ' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T setpoint_temperature;         /* '<Root>/setpoint_temperature' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T temperature;                  /* '<Root>/temperature' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Continuous states (default storage) */
extern X rtX;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Temperature_Control_System0_initialize(void);
extern void Temperature_Control_System0_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Temperature_Control_System/Temperature_Control_System')    - opens subsystem Temperature_Control_System/Temperature_Control_System
 * hilite_system('Temperature_Control_System/Temperature_Control_System/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Temperature_Control_System'
 * '<S1>'   : 'Temperature_Control_System/Temperature_Control_System'
 */
#endif                           /* RTW_HEADER_Temperature_Control_System0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
