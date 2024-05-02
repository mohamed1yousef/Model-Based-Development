/*
 * File: Active_Balancing_Subsystem.h
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

#ifndef RTW_HEADER_Active_Balancing_Subsystem_h_
#define RTW_HEADER_Active_Balancing_Subsystem_h_
#include <math.h>
#ifndef Active_Balancing_Subsystem_COMMON_INCLUDES_
# define Active_Balancing_Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                         /* Active_Balancing_Subsystem_COMMON_INCLUDES_ */

#include "Active_Balancing_Subsystem_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delta;                        /* '<S1>/Active_Balancing_chart' */
  real_T Need_Balance_State;           /* '<S1>/Active_Balancing_chart' */
  real_T lowest;                       /* '<S1>/Active_Balancing_chart' */
  uint32_T previousTicks;              /* '<S1>/Active_Balancing_chart' */
  uint8_T is_active_c3_Active_Balancing_S;/* '<S1>/Active_Balancing_chart' */
  uint8_T is_Decision_Maker;           /* '<S1>/Active_Balancing_chart' */
  uint8_T is_SW_Managment;             /* '<S1>/Active_Balancing_chart' */
  uint8_T temporalCounter_i1;          /* '<S1>/Active_Balancing_chart' */
} DW_Active_Balancing_Subsystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_Active_Balancing_Subs_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block states (default storage) */
extern DW_Active_Balancing_Subsystem_T Active_Balancing_Subsystem_DW;

/* Model entry point functions */
extern void Active_Balancing_Subsystem_initialize(void);
extern void Active_Balancing_Subsystem_step(void);
extern void Active_Balancing_Subsystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Active_Balancing_Sub_T *const Active_Balancing_Subsystem_M;

/* Exported data declaration */

/* Declaration for custom storage class: Global */
extern boolean_T SW_1;                 /* '<S1>/Active_Balancing_chart' */
extern boolean_T SW_2;                 /* '<S1>/Active_Balancing_chart' */
extern boolean_T SW_3;                 /* '<S1>/Active_Balancing_chart' */
extern boolean_T SW_4;                 /* '<S1>/Active_Balancing_chart' */
extern real32_T Voltage_cell_1;        /* '<Root>/Voltage_cell_1' */
extern real32_T Voltage_cell_2;        /* '<Root>/Voltage_cell_2' */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Active_Balancing_Subsystem'
 * '<S1>'   : 'Active_Balancing_Subsystem/Active_Balancing_Subsystem'
 * '<S2>'   : 'Active_Balancing_Subsystem/Active_Balancing_Subsystem/Active_Balancing_chart'
 */
#endif                            /* RTW_HEADER_Active_Balancing_Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
