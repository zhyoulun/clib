//
// Created by zhangyoulun on 2021/4/10.
//

#ifndef CLIB_RBTREE_H
#define CLIB_RBTREE_H

enum rbcolor {
    red, black
};

struct rbnode {
    enum rbcolor color;
    struct rbnode *left;
    struct rbnode *right;
    int key;
};

typedef struct rbnode rbnode;

struct rbtree {
    struct rbnode *root;
    struct rbnode *nil;
};

typedef struct rbtree rbtree;

void rbtree_left_rotate(rbtree *t, rbnode *x);

void rbtree_right_rotate(rbtree *t, rbnode *x);

void rbtree_insert(rbtree *t, rbnode *z);

void rbtree_insert_fixup(rbtree *t, rbnode *z);

void rbtree_transplant(rbtree *t, rbnode *u, rbnode *v);

void rbtree_delete(rbtree *t, rbnode *z);

void rbtree_delete_fixup(rbtree *t, rbnode *x);

#endif //CLIB_RBTREE_H
