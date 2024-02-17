/*
 * File: Automated_Irrigation_Control_Sy.h
 *
 * Code generated for Simulink model 'Automated_Irrigation_Control_Sy'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Feb 17 20:59:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (8-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Automated_Irrigation_Control_Sy_h_
#define RTW_HEADER_Automated_Irrigation_Control_Sy_h_
#ifndef Automated_Irrigation_Control_Sy_COMMON_INCLUDES_
# define Automated_Irrigation_Control_Sy_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                    /* Automated_Irrigation_Control_Sy_COMMON_INCLUDES_ */

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
  real_T Soil_moisture_sensor;         /* '<Root>/Soil_moisture_sensor' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T water_pump_statues;         /* '<Root>/water_pump_statues' */
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
extern void Automated_Irrigation_Control_Sy_initialize(void);
extern void Automated_Irrigation_Control_Sy_step(void);

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
 * hilite_system('Automated_Irrigation/Automated_Irrigation_Control_System')    - opens subsystem Automated_Irrigation/Automated_Irrigation_Control_System
 * hilite_system('Automated_Irrigation/Automated_Irrigation_Control_System/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Automated_Irrigation'
 * '<S1>'   : 'Automated_Irrigation/Automated_Irrigation_Control_System'
 * '<S2>'   : 'Automated_Irrigation/Automated_Irrigation_Control_System/Compare To Constant'
 * '<S3>'   : 'Automated_Irrigation/Automated_Irrigation_Control_System/Compare To Constant1'
 */
#endif                       /* RTW_HEADER_Automated_Irrigation_Control_Sy_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
