/*
 * File: traffic_light_with_urgent_mange.h
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

#ifndef RTW_HEADER_traffic_light_with_urgent_mange_h_
#define RTW_HEADER_traffic_light_with_urgent_mange_h_
#ifndef traffic_light_with_urgent_mange_COMMON_INCLUDES_
# define traffic_light_with_urgent_mange_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                    /* traffic_light_with_urgent_mange_COMMON_INCLUDES_ */

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

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint16_T temporalCounter_i1;   /* '<Root>/traffic_light_with_urgent_manger' */
  uint8_T is_active_c3_traffic_light_with;
                                 /* '<Root>/traffic_light_with_urgent_manger' */
  uint8_T is_c3_traffic_light_with_urgent;
                                 /* '<Root>/traffic_light_with_urgent_manger' */
  uint8_T is_normal;             /* '<Root>/traffic_light_with_urgent_manger' */
  uint8_T is_fault;              /* '<Root>/traffic_light_with_urgent_manger' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T urgent;                       /* '<Root>/urgent' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T red;                          /* '<Root>/red' */
  real_T yellow;                       /* '<Root>/yellow' */
  real_T green;                        /* '<Root>/green' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void traffic_light_with_urgent_mange_initialize(void);
extern void traffic_light_with_urgent_mange_step(void);

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
 * hilite_system('traffic_light_with_urgent_manger/traffic_light_with_urgent_manger')    - opens subsystem traffic_light_with_urgent_manger/traffic_light_with_urgent_manger
 * hilite_system('traffic_light_with_urgent_manger/traffic_light_with_urgent_manger/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'traffic_light_with_urgent_manger'
 * '<S1>'   : 'traffic_light_with_urgent_manger/traffic_light_with_urgent_manger'
 */
#endif                       /* RTW_HEADER_traffic_light_with_urgent_mange_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
