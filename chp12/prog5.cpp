//
// Created by ubril on 9/17/2026.
//


#include <iostream>
#include <memory>
using namespace std;

int main() {


    int ix = 1024, *pi = &ix, *pi2 = new int(2048);

    typedef unique_ptr<int> IntP;

    IntP p2(pi2);
    IntP p0(p2.get());
}