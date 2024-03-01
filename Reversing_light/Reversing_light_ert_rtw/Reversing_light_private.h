/*
 * File: Reversing_light_private.h
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

#ifndef RTW_HEADER_Reversing_light_private_h_
#define RTW_HEADER_Reversing_light_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Reversing_light.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta);
extern void Reversing_li_MATLABFunction(real_T rtu_u, real_T *rty_on, real_T
  *rty_off);

#endif                               /* RTW_HEADER_Reversing_light_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
