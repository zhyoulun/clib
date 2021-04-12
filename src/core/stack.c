//
// Created by zhangyoulun on 2021/4/10.
//

#include "stack.h"

stack *stack_create(void) {
    stack *s = (stack *) malloc(sizeof(stack));
    s->cap = STACK_INIT_SIZE;
    s->arr = (int *) malloc(sizeof(int) * s->cap);
    s->top = 0;
    return s;
}

void stack_resize(stack *s) {
    int *new_arr = (int *) malloc(sizeof(int) * s->cap);
    int *old_arr = s->arr;
    memcpy(new_arr, old_arr, sizeof(int) * s->top);
    s->arr = new_arr;
    free(old_arr);
}

void stack_push(stack *s, int x) {
    if (s->top == s->cap) {
        s->cap *= 2;
        stack_resize(s);
    }
    s->arr[s->top] = x;
    s->top++;
}

int stack_pop(stack *s) {
    assert(s->top > 0);
    s->top--;
    int res = s->arr[s->top];
    if (s->cap > STACK_INIT_SIZE && s->top < s->cap / 2) {
        s->cap /= 2;
        stack_resize(s);
    }
    return res;
}

int stack_top(stack *s) {
    assert(s->top > 0);
    return s->arr[s->top - 1];
}

int stack_empty(stack *s) {
    if (s->top == 0) {
        return 1;
    } else {
        return 0;
    }
}

void stack_print(stack *s) {
    printf("stack: ");
    for (int i = 0; i < s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}