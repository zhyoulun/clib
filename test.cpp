//
// Created by zhangyoulun on 2021/4/10.
//

#include <gtest/gtest.h>

extern "C"
{
#include "src/core/fibonacci.h"
#include "src/core/bstree.h"
#include "src/core/stack.h"
#include "src/core/queue.h"
}

TEST(HelloTest, BasicAssertions) {
    EXPECT_EQ(89, fibonacci(10));
}

TEST(BinarySearchTreeTest, BasicAssertions) {
    bstree *t = bstree_create();
    int a[] = {4, 3, 5, 7, 1, 8, 10, 2, 6, 9};
    for (int i = 0; i < 10; i++) {
        bsnode *z = bstree_create_bsnode();
        z->key = a[i];
        bstree_insert(t, z);
        bstree_inorder_print(t->root);
        printf("------------------------\n");
    }
    bsnode *z = bstree_create_bsnode();
    z->key = 20;
    bstree_insert(t, z);
    bstree_inorder_print(t->root);
}

TEST(StackTest, BasicAssertions) {
    stack *s = stack_create();
    stack_print(s);
    stack_push(s, 1);
    EXPECT_EQ(stack_top(s), 1);
    stack_print(s);
    stack_push(s, 2);
    EXPECT_EQ(stack_top(s), 2);
    stack_print(s);
    stack_push(s, 3);
    EXPECT_EQ(stack_top(s), 3);
    stack_print(s);
    printf("pop: %d\n", stack_pop(s));
    EXPECT_EQ(stack_top(s), 2);
    stack_print(s);
    stack_push(s, 4);
    EXPECT_EQ(stack_top(s), 4);
    stack_print(s);
    stack_push(s, 5);
    EXPECT_EQ(stack_top(s), 5);
    stack_print(s);
    printf("pop: %d\n", stack_pop(s));
    EXPECT_EQ(stack_top(s), 4);
    stack_print(s);
    printf("pop: %d\n", stack_pop(s));
    EXPECT_EQ(stack_top(s), 2);
    stack_print(s);
    printf("pop: %d\n", stack_pop(s));
    EXPECT_EQ(stack_top(s), 1);
    stack_print(s);
    printf("empty: %d\n", stack_empty(s));
    printf("pop: %d\n", stack_pop(s));
    stack_print(s);
    printf("empty: %d\n", stack_empty(s));
    for (int i = 0; i < 100; i++) {
        stack_push(s, i);
    }
    stack_print(s);
    EXPECT_EQ(s->cap, 128);
    for (int i = 0; i < 100; i++) {
        stack_pop(s);
    }
    stack_print(s);
    EXPECT_EQ(s->cap, 8);
}

TEST(QueueTest, BasicAssertions) {
    queue *q = queue_create();
    queue_print(q);
    queue_enqueue(q, 1);
    queue_print(q);
    EXPECT_EQ(queue_head(q), 1);
    EXPECT_EQ(queue_empty(q), 0);
    EXPECT_EQ(queue_dequeue(q), 1);
    for (int i = 0; i < 10; i++) {
        queue_enqueue(q, i);
    }
    queue_print(q);
    EXPECT_EQ(q->cap, 16);
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(queue_dequeue(q), i);
    }
    EXPECT_EQ(q->cap, 8);
}