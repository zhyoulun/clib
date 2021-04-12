//
// Created by zhangyoulun on 2021/4/10.
//


#include "bstree.h"

void bstree_insert(bstree *t, bsnode *z) {
    bsnode *y = NULL;
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

//把t中u子树，和v子树的位置互换
//useless
void bstree_exchange(bstree *t, bsnode *u, bsnode *v) {
    if (u->p == NULL) {//u为t的根节点
        t->root = v;
        u->p = v->p;
        v->p = NULL;
        if (v->p->left == v) {
            v->p->left = u;
        } else {
            v->p->right = u;
        }
    } else if (v->p == NULL) {//v为t的根节点
        bstree_exchange(t, v, u);
    } else {//u和v都不是t的根节点
        bsnode *temp = u->p;
        u->p = v->p;
        v->p = temp;

        if (u->p->left == v) {
            u->p->left = u;
        } else {
            u->p->right = u;
        }
        if (v->p->left == u) {
            v->p->left = v;
        } else {
            v->p->right = v;
        }
    }
}

//将t中用v子树，替代u子树的位置
void bstree_transplant(bstree *t, bsnode *u, bsnode *v) {
    if (u->p == NULL) {//如果u是t的根节点
        t->root = v;
        v->p = u->p;
    } else {//u是非根节点
        if (u->p->left == u) {
            u->p->left = v;
        } else {
            u->p->right = v;
        }
        v->p = u->p;
    }
}

void bstree_delete(bstree *t, bsnode *z) {
    if (z->left == NULL && z->right == NULL) {//z的左右孩子均为null
        if (z->p == NULL) {//z为根节点
            t->root = NULL;
            free(z);
        } else {//z不为根节点
            if (z->p->left == z) {//z为父结点的左子树
                z->p->left = NULL;
                free(z);
            } else {//z为父结点的右子树
                z->p->right = NULL;
                free(z);
            }
        }
    } else if (z->left == NULL) {//z的左子树为null，右子树不为null
        bstree_transplant(t, z, z->right);
        free(z);
//        if (z->p == NULL) {//z为根节点
//            t->root = z->right;
//            z->right->p = NULL;
//            free(z);
//        } else {//z不为根节点
//            if (z->p->left == z) {//z为父结点的左子树
//                z->p->left = z->right;
//                z->right->p = z->p;
//                free(z);
//            } else {//z为父结点的右子树
//                z->p->right = z->right;
//                z->right->p = z->p;
//                free(z);
//            }
//        }
    } else if (z->right == NULL) {//z的左子树不为null，右子树为null
        bstree_transplant(t, z, z->left);
        free(z);
//        if (z->p == NULL) {//z为根节点
//            t->root = z->left;
//            z->left->p = NULL;
//            free(z);
//        } else {//z不为根节点
//            if (z->p->left == z) {//z为父结点的左子树
//                z->p->left = z->left;
//                z->left->p = z->p;
//                free(z);
//            } else {//z为父结点的右子树
//                z->p->right = z->left;
//                z->left->p = z->p;
//                free(z);
//            }
//        }
    } else {//z的left和right均不为null
        bsnode *y = z->right;
        if (y->left == NULL) {//z的右子树，根节点的左子树就null
            bstree_transplant(t, z, y);
            y->left = z->left;
            y->left->p = y;
        } else {
            y = bstree_minimum(y);//找到z->right中的最小节点，此时y->left=null
            bstree_transplant(t, y, y->right);
            y->right = z->right;
            y->right->p = y;
            //如下代码，和if分支中的代码是一样的
            bstree_transplant(t, z, y);
            y->left = z->left;
            y->left->p = y;
        }
    }
}


void bstree_inorder_print_1(bsnode *x, int depth) {
    if (x != NULL) {
        bstree_inorder_print_1(x->left, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf(" ");
        }
        printf("%d\n", x->key);
        bstree_inorder_print_1(x->right, depth + 1);
    }
}

void bstree_inorder_print(bsnode *x) {
    bstree_inorder_print_1(x, 0);
}

void bstree_level_print(bsnode *x) {
    queue *q = queue_create();

}

bstree *bstree_create(void) {
    bstree *t = (bstree *) malloc(sizeof(bstree));
    t->root = NULL;
    return t;
}

bsnode *bstree_create_bsnode(void) {
    bsnode *z = (bsnode *) malloc(sizeof(bsnode));
    z->key = 0;
    z->right = NULL;
    z->left = NULL;
    z->p = NULL;
    return z;
}

bsnode *bstree_minimum(bsnode *x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

bsnode *bstree_maximum(bsnode *x) {
    while (x->right != NULL) {
        x = x->right;
    }
    return x;
}