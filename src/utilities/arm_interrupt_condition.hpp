// Copyright 2020 Embedded Artistry LLC
// SPDX-License-Identifier: MIT

#ifndef ARM_INTERRUPT_CONDITION_HPP_
#define ARM_INTERRUPT_CONDITION_HPP_

/** Interrupt Condition specialized for ARM processors
 *
 */
class ARMInterruptConditionVariable
{
  public:
	template<typename TLock>
	void wait(TLock& lock) noexcept
	{
		// no need to unlock (re-enable interrupts)
		static_cast<void>(lock);
		__asm volatile("wfi");
	}

	void notify_one() const noexcept
	{
		// Nothing to do, pending interrupt will cause wfi
		// to exit even with interrupts disabled
	}

	void notify_all() const noexcept
	{
		// Nothing to do, pending interrupt will cause wfi
		// to exit even with interrupts disabled
	}
};

#endif // ARM_INTERRUPT_CONDITION_HPP_
