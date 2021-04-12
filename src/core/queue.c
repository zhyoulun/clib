//
// Created by zhangyoulun on 2021/4/11.
//

#include "queue.h"

queue *queue_create(void) {
    queue *q = (queue *) malloc(sizeof(queue));
    q->size = 0;
    q->front = -1;
    q->rear = -1;
    q->cap = QUEUE_INIT_SIZE;
    q->arr = (int *) malloc(sizeof(int) * q->cap);
    return q;
}

void queue_resize(queue *q, int new_cap) {
    int *new_arr = (int *) malloc(sizeof(int) * new_cap);
    int index = q->front;
    for (int i = 0; i < q->size; i++) {
        index++;
        index %= q->cap;
        new_arr[i] = q->arr[index];
    }
    q->front = -1;
    q->rear = q->size - 1;
    q->cap = new_cap;
    int *old_arr = q->arr;
    q->arr = new_arr;
    free(old_arr);
}

void queue_enqueue(queue *q, int x) {
    if (q->size == q->cap) {
        queue_resize(q, q->cap * 2);
    }
    q->rear++;
    q->rear %= q->cap;
    q->size++;
    q->arr[q->rear] = x;
}

int queue_dequeue(queue *q) {
    assert(q->size > 0);
    q->front++;
    q->front %= q->cap;
    q->size--;
    int res = q->arr[q->front];
    if (q->cap > QUEUE_INIT_SIZE && q->size < q->cap / 2) {
        queue_resize(q, q->cap / 2);
    }
    return res;
}

int queue_empty(queue *q) {
    return q->size == 0;
}

int queue_head(queue *q) {
    assert(q->size > 0);
    return q->arr[(q->front + 1) % q->cap];
}

void queue_print(queue *q) {
    int index = q->front;
    printf("queue: ");
    for (int i = 0; i < q->size; i++) {
        index++;
        index %= q->cap;
        printf("%d ", q->arr[index]);
    }
    printf("\n");
}