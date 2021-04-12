//
// Created by zhangyoulun on 2021/4/10.
//

#ifndef CLIB_STACK_H
#define CLIB_STACK_H

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#define STACK_INIT_SIZE 8

struct stack {
    int *arr;
    int cap;
    // top=0，代表栈为空；
    // top=cap，代表栈已经存满；
    // top代表的索引，是即将被插入数据的位置
    int top;
};

typedef struct stack stack;

stack *stack_create(void);

void stack_push(stack *s, int x);

int stack_pop(stack *s);

void stack_print(stack *s);

int stack_empty(stack *s);

int stack_top(stack *s);

#endif //CLIB_STACK_H
