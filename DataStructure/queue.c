#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Queue *create_queue(unsigned capacity) {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity*sizeof(int));
    return queue;
}

int is_full(struct Queue *queue) {
    return (queue->size == queue->capacity);
}

int is_empty(struct Queue *queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int item) {
    if (is_full(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue *queue) {
    if (is_empty(queue)) return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int get_front(struct Queue *queue) {
    if (is_empty(queue)) return INT_MIN;
    return queue->array[queue->front];
}
int get_rear(struct Queue *queue) {
    if (is_empty(queue)) return INT_MIN;
    return queue->array[queue->rear];
}

int main() {
    struct Queue *queue;

    queue = create_queue(100);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n", dequeue(queue));
    printf("Front item is %d\n", get_front(queue));
    printf("Rear item is %d\n", get_rear(queue));

    return 0;
}

