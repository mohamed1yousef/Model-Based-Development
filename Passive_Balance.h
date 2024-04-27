/*
 * File: Passive_Balance.h
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

#ifndef RTW_HEADER_Passive_Balance_h_
#define RTW_HEADER_Passive_Balance_h_
#ifndef Passive_Balance_COMMON_INCLUDES_
# define Passive_Balance_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Passive_Balance_COMMON_INCLUDES_ */

#include "Passive_Balance_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Lowest_B;                     /* '<S1>/Passive_Balance_Chart' */
  real_T state;                        /* '<S1>/Passive_Balance_Chart' */
  uint8_T is_active_c1_Passive_Balance;/* '<S1>/Passive_Balance_Chart' */
  uint8_T is_Balancer;                 /* '<S1>/Passive_Balance_Chart' */
  uint8_T is_Mange_Sw;                 /* '<S1>/Passive_Balance_Chart' */
} DW_Passive_Balance_T;

/* Real-time Model Data Structure */
struct tag_RTM_Passive_Balance_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Passive_Balance_T Passive_Balance_DW;

/* Model entry point functions */
extern void Passive_Balance_initialize(void);
extern void Passive_Balance_step(void);
extern void Passive_Balance_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Passive_Balance_T *const Passive_Balance_M;

/* Exported data declaration */

/* Declaration for custom storage class: Global */
extern boolean_T Cell1_Sw;             /* '<S1>/Passive_Balance_Chart' */
extern boolean_T Cell2_Sw;             /* '<S1>/Passive_Balance_Chart' */
extern boolean_T Cell3_Sw;             /* '<S1>/Passive_Balance_Chart' */
extern real32_T Voltage_cell_1;        /* '<Root>/Voltage_cell_1' */
extern real32_T Voltage_cell_2;        /* '<Root>/Voltage_cell_2' */
extern real32_T Voltage_cell_3;        /* '<Root>/Voltage_cell_3' */

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
 * '<Root>' : 'Passive_Balance'
 * '<S1>'   : 'Passive_Balance/Passive_Balance_System'
 * '<S2>'   : 'Passive_Balance/Passive_Balance_System/Passive_Balance_Chart'
 */
#endif                                 /* RTW_HEADER_Passive_Balance_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
