//
// Created by zhangyoulun on 2021/4/11.
//

#ifndef CLIB_QUEUE_H
#define CLIB_QUEUE_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define QUEUE_INIT_SIZE 8

#ifdef __cplusplus
extern "C" {
#endif

struct queue {
    void *arr;
    int front;//队头指针
    int rear;//队尾指针
    int size;//存储数据的个数
    int cap;//队列容量
    int type_size;//元素类型大小，如果是int，则为sizeof(int)
};

typedef struct queue queue;

queue *queue_create(int type_size);

void queue_enqueue(queue *q, void *x);

void *queue_dequeue(queue *q);

int queue_empty(queue *q);

void *queue_head(queue *q);

void queue_print(queue *q);

#ifdef __cplusplus
}
#endif

#endif //CLIB_QUEUE_H
