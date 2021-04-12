#include <iostream>

extern "C"
{
#include "src/core/fibonacci.h"
#include "src/core/bstree.h"
}

int main() {
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
//    std::cout << "Hello, World!" << std::endl;
//    std::cout << fibonacci(10) << std::endl;
    return 0;
}
