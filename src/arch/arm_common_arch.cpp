#include "arm_common_arch.hpp"
#include <processor_includes.hpp> // Processor-specific include that contains headers/defines

void ARMCommonArch::interruptsEnable_() noexcept
{
	__enable_irq();
}

void ARMCommonArch::interruptsDisable_() noexcept
{
	__disable_irq();
}

void ARMCommonArch::memoryBarrier_() noexcept
{
	__DSB();
}

void ARMCommonArch::instructionBarrier_() noexcept
{
	__ISB();
}

void ARMCommonArch::systemReset() noexcept
{
	NVIC_SystemReset();
}

void ARMCommonArch::sysTickConfig(uint32_t ticks) noexcept
{
	sysTickConfig(ticks);
}
