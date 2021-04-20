//
// Created by zhangyoulun on 2021/4/11.
//

#include "queue.h"

queue *queue_create(int type_size) {
    queue *q = (queue *) malloc(sizeof(queue));
    q->size = 0;
    q->front = -1;
    q->rear = -1;
    q->cap = QUEUE_INIT_SIZE;
    q->type_size = type_size;
    q->arr = (void *) malloc(q->type_size * q->cap);
    return q;
}

void queue_copy_element(void *src, void *dst, int type_size) {
    for (int i = 0; i < type_size; i++) {
        *(((uint8_t *) dst) + i) = *(((uint8_t *) src) + i);
    }
}

void *queue_arr_pos(void *arr, int index, int type_size) {
    return (void *) (((uint8_t *) arr) + index * type_size);
}

void queue_resize(queue *q, int new_cap) {
    void *new_arr = (void *) malloc(q->type_size * new_cap);
    int index = q->front;
    for (int i = 0; i < q->size; i++) {
        index++;
        index %= q->cap;
//        new_arr[i] = q->arr[index];
        queue_copy_element(queue_arr_pos(q->arr, index, q->type_size), queue_arr_pos(new_arr, i, q->type_size),
                           q->type_size);
    }
    q->front = -1;
    q->rear = q->size - 1;
    q->cap = new_cap;
    void *old_arr = q->arr;
    q->arr = new_arr;
    free(old_arr);
}

void queue_enqueue(queue *q, void *x) {
    if (q->size == q->cap) {
        queue_resize(q, q->cap * 2);
    }
    q->rear++;
    q->rear %= q->cap;
    q->size++;
//    q->arr[q->rear] = x;
    queue_copy_element(x, queue_arr_pos(q->arr, q->rear, q->type_size), q->type_size);
}

void *queue_dequeue(queue *q) {
    assert(q->size > 0);
    q->front++;
    q->front %= q->cap;
    q->size--;
//    int res = q->arr[q->front];
    void *res = (void *) malloc(q->type_size);
    queue_copy_element(queue_arr_pos(q->arr, q->front, q->type_size), res, q->type_size);
    if (q->cap > QUEUE_INIT_SIZE && q->size < q->cap / 2) {
        queue_resize(q, q->cap / 2);
    }
    return res;
}

int queue_empty(queue *q) {
    return q->size == 0;
}

void *queue_head(queue *q) {
    assert(q->size > 0);
    int index = (q->front + 1) % q->cap;
//    return q->arr[index];
    void *res = (void *) malloc(q->type_size);
    queue_copy_element(queue_arr_pos(q->arr, index, q->type_size), res, q->type_size);
    return res;
}

void queue_print(queue *q) {
//    int index = q->front;
//    printf("queue: ");
//    for (int i = 0; i < q->size; i++) {
//        index++;
//        index %= q->cap;
//        printf("%d ", q->arr[index]);
//    }
//    printf("\n");
}