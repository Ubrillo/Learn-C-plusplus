//
// Created by ubril on 10/6/2026.
//
#include "prog1.h"


int fact(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}