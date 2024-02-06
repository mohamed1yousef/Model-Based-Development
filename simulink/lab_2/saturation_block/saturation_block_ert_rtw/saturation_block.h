/*
 * File: saturation_block.h
 *
 * Code generated for Simulink model 'saturation_block'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Feb  6 16:42:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_saturation_block_h_
#define RTW_HEADER_saturation_block_h_
#ifndef saturation_block_COMMON_INCLUDES_
# define saturation_block_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* saturation_block_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T input_signal;                 /* '<Root>/input_signal' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T output_signal;                /* '<Root>/output_signal' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void saturation_block_initialize(void);
extern void saturation_block_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'saturation_block'
 * '<S1>'   : 'saturation_block/saturation_block'
 */
#endif                                 /* RTW_HEADER_saturation_block_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
