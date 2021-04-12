//
// Created by zhangyoulun on 2021/4/11.
//

#ifndef CLIB_QUEUE_H
#define CLIB_QUEUE_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define QUEUE_INIT_SIZE 8

struct queue {
    int *arr;
    int front;//队头指针
    int rear;//队尾指针
    int size;//存储数据的个数
    int cap;//队列容量
};

typedef struct queue queue;

queue *queue_create(void);

void queue_enqueue(queue *q, int x);

int queue_dequeue(queue *q);

int queue_empty(queue *q);

int queue_head(queue *q);

void queue_print(queue *q);


#endif //CLIB_QUEUE_H
