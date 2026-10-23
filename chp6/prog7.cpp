//
// Created by ubril on 10/8/2026.
//

#include<iostream>
#include<string>
using namespace std;


string (&func(string ss))[10];

using arrST = string[10];
arrST (&funcStr(string ss))[10];

auto funcX(string ss) -> string(*)[10];

int odd[] = {1,3,5,7,9};
int even[] = {2,4,6,8,10};

decltype(odd) &arrPtr(int i) {
    return (i % 2) ? odd : even;
}

int main() {
    // typedef int arrT[10];
    // int arr[10];
    // int *p1[10];
    // int (*p2)[10] = &arr;

    decltype(odd) &a = arrPtr(3);
    cout << a[4] << endl;
}