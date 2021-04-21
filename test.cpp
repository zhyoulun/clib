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
    bsnode *ten_node;
    bsnode *eight_node;
    bsnode *four_node;
    for (int i = 0; i < 10; i++) {
        bsnode *z = bstree_create_bsnode();
        z->key = a[i];
        if (a[i] == 10) {
            ten_node = z;
        } else if (a[i] == 8) {
            eight_node = z;
        } else if (a[i] == 4) {
            four_node = z;
        }
        bstree_insert(t, z);
//        bstree_inorder_print(t->root);
//        printf("------------------------\n");
    }
    bsnode *z = bstree_create_bsnode();
    z->key = 20;
    bstree_insert(t, z);
    bstree_inorder_print(t);
    bstree_level_print(t);
    bstree_delete(t, ten_node);
    bstree_inorder_print(t);
    bstree_delete(t, eight_node);
    bstree_inorder_print(t);
    bstree_delete(t, four_node);
    bstree_inorder_print(t);
}

TEST(BinarySearchTreeTest2, BasicAssertions) {
    bstree *t = bstree_create();
    bsnode *z = bstree_create_bsnode();
    z->key = 1;
    bstree_insert(t, z);
    bstree_inorder_print(t);
    EXPECT_EQ(t->root->key, 1);
    bstree_delete(t, z);
    bstree_inorder_print(t);
    EXPECT_EQ(t->root, (bsnode *) NULL);
}

TEST(BinarySearchTreeTest3, BasicAssertions) {
    bstree *t = bstree_create();
    bsnode *one_node = bstree_create_bsnode();
    one_node->key = 1;
    bstree_insert(t, one_node);
    bsnode *two_node = bstree_create_bsnode();
    two_node->key = 2;
    bstree_insert(t, two_node);

    bstree_inorder_print(t);
    EXPECT_EQ(t->root->key, 1);
    bstree_delete(t, one_node);
    bstree_inorder_print(t);
    EXPECT_EQ(t->root, two_node);
}

TEST(BinarySearchTreeTest4, BasicAssertions) {
    bstree *t = bstree_create();
    bsnode *one_node = bstree_create_bsnode();
    one_node->key = 1;
    bstree_insert(t, one_node);
    bsnode *two_node = bstree_create_bsnode();
    two_node->key = 2;
    bstree_insert(t, two_node);

    bstree_inorder_print(t);
    EXPECT_EQ(t->root->key, 1);
    bstree_delete(t, two_node);
    bstree_inorder_print(t);
    EXPECT_EQ(t->root, one_node);
}

TEST(BinarySearchTreeTest5, BasicAssertions) {
    bstree *t = bstree_create();
    bsnode *three_node = bstree_create_bsnode();
    three_node->key = 3;
    bstree_insert(t, three_node);
    bsnode *two_node = bstree_create_bsnode();
    two_node->key = 2;
    bstree_insert(t, two_node);

    bstree_inorder_print(t);
    EXPECT_EQ(t->root->key, 3);
    bstree_delete(t, two_node);
    bstree_inorder_print(t);
    EXPECT_EQ(t->root, three_node);
}


TEST(BinarySearchTreeTest6, BasicAssertions) {
    bstree *t = bstree_create();
    bsnode *three_node = bstree_create_bsnode();
    three_node->key = 3;
    bstree_insert(t, three_node);
    bsnode *two_node = bstree_create_bsnode();
    two_node->key = 2;
    bstree_insert(t, two_node);
    bsnode *one_node = bstree_create_bsnode();
    one_node->key = 1;
    bstree_insert(t, one_node);

    bstree_inorder_print(t);
    EXPECT_EQ(t->root->key, 3);
    bstree_delete(t, two_node);
    bstree_inorder_print(t);
    EXPECT_EQ(t->root, three_node);
}

//TEST(BinarySearchTreeTest7, BasicAssertions) {
//    bstree *t = bstree_create();
//    int a[] = {4, 3, 5, 7, 1, 80, 100, 2, 6, 90, 75};
//    bsnode *seven_node;
//    for (int i = 0; i < 11; i++) {
//        bsnode *z = bstree_create_bsnode();
//        z->key = a[i];
//        if (a[i] == 7) {
//            seven_node = z;
//        }
//        bstree_insert(t, z);
//    }
////    bsnode *z = bstree_create_bsnode();
////    z->key = 20;
////    bstree_insert(t, z);
//    bstree_inorder_print(t);
//    bstree_delete(t, seven_node);
//    bstree_inorder_print(t);
//}


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
    queue *q = queue_create(sizeof(int));
    queue_print(q);
    int a = 1;
    queue_enqueue(q, &a);
    queue_print(q);
    EXPECT_EQ(*(int *) queue_head(q), a);
    EXPECT_EQ(queue_empty(q), 0);
    EXPECT_EQ(*(int *) queue_dequeue(q), a);
    for (int i = 0; i < 10; i++) {
        queue_enqueue(q, &i);
    }
    queue_print(q);
    EXPECT_EQ(q->cap, 16);
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(*(int *) queue_dequeue(q), i);
    }
    EXPECT_EQ(q->cap, 8);
}

TEST(QueueTest2, BasicAssertions) {
    queue *q = queue_create(sizeof(float));
    queue_print(q);
    float a = 1;
    queue_enqueue(q, &a);
    queue_print(q);
    EXPECT_EQ(*(float *) queue_head(q), a);
    EXPECT_EQ(queue_empty(q), 0);
    EXPECT_EQ(*(float *) queue_dequeue(q), a);
    for (int i = 0; i < 10; i++) {
        float ii = float(i);
        queue_enqueue(q, &ii);
    }
    queue_print(q);
    EXPECT_EQ(q->cap, 16);
    for (int i = 0; i < 10; i++) {
        float ii = float(i);
        EXPECT_EQ(*(float *) queue_dequeue(q), ii);
    }
    EXPECT_EQ(q->cap, 8);
}

TEST(QueueTest3, BasicAssertions) {
    struct people {
        char name;
        int age;
    };

    queue *q = queue_create(sizeof(struct people));
    queue_print(q);
    struct people a = {.name = 'a', .age = 1};
    queue_enqueue(q, &a);
    queue_print(q);
    struct people *got = (struct people *) queue_head(q);
    EXPECT_EQ((*got).name, a.name);
    EXPECT_EQ((*got).age, a.age);
    EXPECT_EQ(queue_empty(q), 0);
    got = (struct people *) queue_dequeue(q);
    EXPECT_EQ((*got).name, a.name);
    EXPECT_EQ((*got).age, a.age);
    for (int i = 0; i < 10; i++) {
        struct people aa = {.name = 'a', .age = i};
        queue_enqueue(q, &aa);
    }
    queue_print(q);
    EXPECT_EQ(q->cap, 16);
    for (int i = 0; i < 10; i++) {
        struct people aa = {.name = 'a', .age = i};
        got = (struct people *) queue_dequeue(q);
        EXPECT_EQ((*got).name, 'a');
        EXPECT_EQ((*got).age, i);
    }
    EXPECT_EQ(q->cap, 8);
}