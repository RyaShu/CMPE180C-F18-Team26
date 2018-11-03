#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

typedef int buffer_item;
#define BUFFER_SIZE 10

//function declaration
int insert_item(buffer_item item);
int remove_item(buffer_item *item);
void* Producer();
void* Consumer();

buffer_item buffer[BUFFER_SIZE]; // buffer is a integer array
pthread_mutex_t mutex; // mutex lock protects the actual insertion or removal of items in the buffer
sem_t full, empty;
int count = 0;
int main(int argc, char* argv[]) {
    /* 1. Get command line argument.
     *    a. duration of sleeping before terminating
     *    b. number of producer thread
     *    c. number of consumer thread
     */
     int sleepTime = atoi(argv[1]);
     int numProducer = atoi(argv[2]);
     int numConsumer = atoi(argv[3]);


     // 2. Initialize each element of the buffer to 0;
     for(int i = 0; i < BUFFER_SIZE; i++){
           buffer[i] = 0;
     }

     sem_init(&full, 0, 0);
     sem_init(&empty,0, BUFFER_SIZE);

     // 3. Create producer threads

     pthread_t tidProducer;
     pthread_t tidConsumer;

     for(int i = 0; i < numProducer; i++){
        pthread_create(&tidProducer,NULL,Producer,NULL);
    }

    // 4. Create consumer threads
    for(int i = 0; i < numConsumer; i++){
      pthread_create(&tidConsumer,NULL,Consumer,NULL);
    }

  // 5. Sleep
       sleep(sleepTime);
  //6. Exit
       return 0;

}


int insert_item(buffer_item item){
    /* insert item into buffer
     * return 0 if successful,
     * otherwise return -1 indicating an error condition */

    sem_wait(&empty);

    if(count >= 0 && count < BUFFER_SIZE) {
        pthread_mutex_lock(&mutex);
        buffer[count] = item;
        count++;
        for(int i = 0; i < BUFFER_SIZE; i++){
            printf("%d ", buffer[i]);
        }
        printf("\n");

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        printf("the buffer is ");
        return 0;
    }else {
        return -1;
    }

}


int remove_item(buffer_item *item){
    /* remove an object from buffer placing it in item
     * return 0 if successful,otherwise
     * return -1 indicating an error condition
     */


    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    if(count > 0 && count <= BUFFER_SIZE) {


        *item = buffer[count - 1];
        buffer[count - 1] = 0;
        count--;

        for(int i = 0; i < BUFFER_SIZE; i++){
            printf("%d ", buffer[i]);
        }
        printf("\n");

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        return 0;
    }else{
        return -1;
    }
}


void* Producer(){
      buffer_item  item;

      while(1) {
          srand(time(NULL));
          sleep(rand()%10);
          item = rand() % 10 + 1;
          if(insert_item(item) == 0){
              printf("Successfully produce %d to the buffer\n", item);
              printf("\n");
          }else{
              printf("producer error found\n");
              printf("\n");
          }
      }
}


void* Consumer(){
    buffer_item item ;

    while(1) {
        sleep(rand()%10);
        if(remove_item(&item) == 0){
            printf("Successfully removed the item %d of the buffer\n", item);
            printf("\n");
        }else{
            printf("consumer error found\n");
            printf("\n");
        }
    }
}