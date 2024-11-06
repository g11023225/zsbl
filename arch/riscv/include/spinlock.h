#ifndef __RISCV_LOCKS_H__
#define __RISCV_LOCKS_H__

typedef struct {
	volatile long lock;
} spinlock_t;

#define __RISCV_SPIN_UNLOCKED 0

#define SPIN_LOCK_INIT(_lptr) (_lptr)->lock = __RISCV_SPIN_UNLOCKED

#define SPIN_LOCK_INITIALIZER                  \
	{                                      \
		.lock = __RISCV_SPIN_UNLOCKED, \
	}

int spin_lock_check(spinlock_t *lock);

int spin_trylock(spinlock_t *lock);

void spin_lock(spinlock_t *lock);

void spin_unlock(spinlock_t *lock);

#endif
