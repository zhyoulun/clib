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

#endif //CLIB_RBTREE_H
