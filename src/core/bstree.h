//
// Created by zhangyoulun on 2021/4/10.
// 二叉搜索树 binary search tree

#ifndef CLIB_BSTREE_H
#define CLIB_BSTREE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct bsnode {
    struct bsnode *left;//左孩子
    struct bsnode *right;//右孩子
    struct bsnode *p;//父亲
    int key;
};

typedef struct bsnode bsnode;

struct bstree {
    struct bsnode *root;
};

typedef struct bstree bstree;

//向二叉搜索树t中插入一个节点z
void bstree_insert(bstree *t, bsnode *z);

//删除一个节点
void bstree_delete(bstree *t, bsnode *z);

//中序遍历
void bstree_inorder_print(bsnode *x);

void bstree_level_print(bsnode *x);

//创建一个空树
bstree *bstree_create(void);

//创建一个空节点
bsnode *bstree_create_bsnode(void);

//找到树中值最小的节点
bsnode *bstree_minimum(bsnode *x);

//找到树中值最大的节点
bsnode *bstree_maximum(bsnode *x);

#endif //CLIB_BSTREE_H
