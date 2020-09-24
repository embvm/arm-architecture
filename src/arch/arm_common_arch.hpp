#ifndef ARM_COMMON_ARCHITECTURE_HPP_
#define ARM_COMMON_ARCHITECTURE_HPP_

#include <cassert>
#include <cstdint>
#include <processor/virtual_processor_arch.hpp>

#if 0
ARM recommends that the architectural requirements are adopted.
If it is necessary to ensure a pended interrupt is recognized before subsequent operations, the ISB instruction should be used after CPSIE I. Figure 16 shows the use of the ISB instruction after enabling interrupts to permit immediate recognition of the pending interrupt.
If it is not necessary to ensure that a pended interrupt will be recognized immediately before subsequent operations, it is not necessary to insert a memory barrier instruction.
Between two time critical tasks, if you want to permit a pended interrupt to take place, you can use an ISB instruction as follows:
__enable_irq(); // CPSIE I : Enable interrupt
__ISB(); // Allow pended interrupts to be recognized
__disable_irq(); // CPSID I : Disable interrupt
A suitable architectural coding is:
__disable_irq(); /* CPSID I */
critical_task1();
__enable_irq(); /* CPSIE I */
__ISB(); // Interrupt can take place between ISB and disable_irq
__disable_irq();
critical_task2();
__enable_irq();

http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dai0321a/BIHBFEIB.html
#endif

class ARMCommonArch : public embvm::VirtualProcessorArchBase<ARMCommonArch>
{
  public:
#pragma mark - ARM Specific Arch Functions -
	static void systemReset() noexcept;

	static void sysTickConfig(uint32_t ticks) noexcept;

#pragma mark - Common Arch Functions -
	static void interruptsEnable_() noexcept;

	static void interruptsDisable_() noexcept;

	static void memoryBarrier_() noexcept;

	static void instructionBarrier_() noexcept;
};

#endif // ARM_COMMON_ARCHITECTURE_HPP_
