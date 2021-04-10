//
// Created by zhangyoulun on 2021/4/10.
//

#include "fibonacci.h"

int fibonacci(int a) {
    if (a < 2) {
        return 1;
    } else {
        return fibonacci(a - 1) + fibonacci(a - 2);
    }
}

