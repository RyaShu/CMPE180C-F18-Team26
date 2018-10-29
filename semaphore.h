#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H

#include <stdint.h>
#include <sys/types.h>

typedef struct semaphore* sem_type;

// create a semaphore
semtype sem_create(size_t count);

// destory a semaphore
int sem_destory(sem_type sem);

// wait operation for a semaphore
int wait(sem_type sem);

// signal operation for a semaphore
int signal(sem_type sem);

#endif
