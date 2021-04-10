//
// Created by zhangyoulun on 2021/4/10.
//

#include <stddef.h>
#include "bstree.h"

void bstree_insert(bstree *t, bsnode *z) {
    bsnode *y;
    bsnode *x = t->root;
    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->p = y;
    if (y == NULL) {
        t->root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}