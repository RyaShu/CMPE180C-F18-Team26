queue_type queue_create(void);

int queue_destroy(queue_type queue);

int queue_enqueue(queue_type queue, void* data);

int queue_dequeue(queue_t queue, void **data);

int queue_delete(queue_type queue, void* data);

int queue_length(queue_type queue);
