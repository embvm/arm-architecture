// Copyright 2020 Embedded Artistry LLC
// SPDX-License-Identifier: MIT

#ifndef ARM_INTERRUPT_LOCK_HPP_
#define ARM_INTERRUPT_LOCK_HPP_

#include <cstdint>

class ARMInterruptLock
{
  public:
	ARMInterruptLock() noexcept : flags_(0) {}

	~ARMInterruptLock() = default;

	void lock() noexcept
	{
		__asm volatile("mrs %0, cpsr" : "=r"(flags_)); // store flags
		__asm volatile("cpsid i"); // disable interrupts
	}

	void unlock() noexcept
	{
		if((flags_ & mask) == 0)
		{
			// Was previously enabled
			__asm volatile("cpsie i"); // enable interrupts
		}
	}

  private:
	volatile uint32_t flags_;

	// CPSR and APSR flag # 7 is IRQ (6 is FIW)
	// http://lioncash.github.io/ARMBook/apsr_and_cpsr_flags.html
	static constexpr uint32_t mask = (1 << 7);
};

#endif // ARM_INTERRUPT_LOCK_HPP_
