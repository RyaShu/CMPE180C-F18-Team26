#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct queue* queue_type

queue_type queue_create(void);

int queue_destroy(queue_type queue);

int queue_enqueue(queue_type queue, void* data);

int queue_dequeue(queue_t queue, void **data);

int queue_delete(queue_type queue, void* data);

int queue_length(queue_type queue);
