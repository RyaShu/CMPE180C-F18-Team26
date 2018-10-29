#include "semaphore.h"
#include ""

struct semaphore{
  int counter;
  struct process* list;
}


semaphore* sem_create(size_t count){
   struct semaphore* new_semaphore = malloc(sizeof(struct semaphore));
   new_semaphore -> counter = count;
   new_semaphore -> list = queue_create();
}

int sem_destory(sem_type sem){
    if(sem_type == NULL || queue_length(sem -> list) > 0){
      return -1;
    }
}

// wait operation for a semaphore
int wait(sem_type sem){
    if(sem_type == NULL){
       return -1;
    }
    // need to make the following code atomic
    while(sem -> counter ==0){
      pthread_t

    }

}

// signal operation for a semaphore
int signal(semaphore* sem){

}
