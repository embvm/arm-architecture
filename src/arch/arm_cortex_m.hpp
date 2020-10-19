#ifndef ARM_CORTEX_M_COMMON_ARCHITECTURE_HPP_
#define ARM_CORTEX_M_COMMON_ARCHITECTURE_HPP_

#include "arm_common_arch.hpp"

/*
 * The Cortex-M3 and M4 are the same with the significant difference that Cortex-M4 has
 * 1) DSP extensions and
 * 2) Optional FPU
 */

// Currently there are no differences between ARM common arch and Cortex-M
using ARMCortexMArch = ARMCommonArch;

#endif // ARM_CORTEX_M_COMMON_ARCHITECTURE_HPP_
