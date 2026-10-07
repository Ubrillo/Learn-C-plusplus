//
// Created by ubril on 10/6/2026.
//


#include <iostream>
using namespace std;

void sumList(initializer_list<int> list) {
    for (auto beg = list.begin(); beg != list.end(); ++beg) {
        cout << *beg << endl;
    }
}

int main()
{
    sumList({1, 2, 3, 4, 5});
}