//
// Created by ubril on 10/6/2026.
//


#include <iostream>

using namespace std;

//ex6.21
int largest(const int *p, int a) {
    return (*p > a)  ? *p : a;
}

//ex6.22
void swap(int *p1, int *p2) {
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}

//ex6.23
void print(const int *beg, const int *end) {
    while (beg != end) {
        cout << *beg++ << endl;
    }
}



int main() {
    // int a = 5;
    // int b = 10;
    // //swap(&a, &b);
    // cout << a << "-" <<  b << endl;

    int i =0,  j[2] = {0, 1};
    print(begin(j), end(j));
}