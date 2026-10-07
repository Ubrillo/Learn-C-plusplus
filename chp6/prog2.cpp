//
// Created by ubril on 10/6/2026.
//
#include <iostream>
using namespace std;


void swap(int *pa, int *pb) {
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}


// Ex6.11

void reset(int *&p) {
    *p = 0;
}


string::size_type find_char(const string &s, char c,
    string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i=0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) {
                ret = i;
            }
            ++occurs;
        }
    }
    return ret;
}

int main() {
    // int a = 5, b = 6;
    // int *pa = &a, *pb = &b;
    // swap(&a, &b);
    //
    // cout << a << b << endl;

    int x = 5;
    int *p = &x;
    reset(p);
    cout << x << endl;
}