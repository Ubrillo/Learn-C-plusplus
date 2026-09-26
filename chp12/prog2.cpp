//
// Created by ubril on 9/15/2026.
//

#include<iostream>
#include <vector>
#include<memory>
using namespace std;


vector<int>* vmemAllocator () {
    vector<int> *v = new vector<int>();
    return v;
}

shared_ptr<vector<int>> vmemAllocator2 () {
    shared_ptr<vector<int>> v = make_shared<vector<int>>();
    return v;
}


vector<int>* vassigned() {
    vector<int> *vec = vmemAllocator();
    cout << "enter 10 elements:"<< endl;
    for (int i=0; i<10; i++) {
        int element;
        cin >> element;
        vec->push_back(element);
    }

    return vec;
}


shared_ptr<vector<int>> vassigned2() {
    shared_ptr vec = vmemAllocator2();
    cout << "enter 10 elements:"<< endl;

    for (int i=0; i<10; i++) {
        int e;
        cin >> e;
        vec->push_back(e);
    }
    return vec;
}

void printVector() {
    auto vec = vassigned();
    cout << "printing elements:" << endl;
    for (auto e: *vec) {
        cout << e << endl;
    }
    delete vec;
    vec = nullptr;
}


void printVector2() {
    auto vec = vassigned2();
    cout << "printing elements:" << endl;

    for (auto e: *vec) {
        cout << e << endl;
    }
    cout << vec.use_count() << endl;
}

int main()
{
    // int *pi = new int(1024);
    // cout << *pi << endl;
    //
    // string *ps = new string(10, '9');
    // cout << *ps << endl;
    //
    // vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};
    //
    // for (auto i: *pv) {
    //     cout << i << endl;
    // }
    //
    // int *p1 = new (nothrow) int;
    // cout << *p1 << endl;

    printVector2();

}