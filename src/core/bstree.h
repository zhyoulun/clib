//
// Created by zhangyoulun on 2021/4/10.
// 二叉搜索树 binary search tree

#ifndef CLIB_BSTREE_H
#define CLIB_BSTREE_H

//#include "../../clib.del/src/utils/munit/munit.h"

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

//static MunitResult test_bstree(const MunitParameter params[], void *user_data) {
//    bstree *t = (bstree *) malloc(sizeof(bstree *));
//    bsnode *z = (bsnode *) malloc(sizeof(bsnode *));
//    z->key = 10;
//    bstree_insert(t, z);
//    return MUNIT_OK;
//}

#endif //CLIB_BSTREE_H
