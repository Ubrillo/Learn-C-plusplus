//
// Created by ubril on 10/6/2026.
//

#include<iostream>
#include "prog1.h"
using namespace std;

int main() {
    cout << fact(5) << endl;


    //cout << abs(-1) << endl;

    // for (size_t i=0; i<10; i++) {
    //     cout << count_calls() << endl;
    // }
}


int abs(int val) {
    return val < 0 ? -val : val;
}


size_t count_calls() {
    static size_t ctr = 0;
    return ctr++;
}
