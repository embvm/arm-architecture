// Copyright 2020 Embedded Artistry LLC
// SPDX-License-Identifier: MIT

#ifndef THUMB_INTERRUPT_LOCK_HPP_
#define THUMB_INTERRUPT_LOCK_HPP_

#include <cstdint>

class ThumbInterruptLock
{
  public:
	ThumbInterruptLock() noexcept : flags_(0) {}

	~ThumbInterruptLock() = default;

	void lock() noexcept
	{
		__asm volatile("mrs %0, primask" : "=r"(flags_)); // store flags
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

	// FAULTMASK[0]: 0 == no effect, 1 == prevent activation of all exceptions except NMI
	// http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0552a/CHDBIBGJ.html
	static constexpr uint32_t mask = (1 << 0);
};

#endif // THUMB_INTERRUPT_LOCK_HPP_
