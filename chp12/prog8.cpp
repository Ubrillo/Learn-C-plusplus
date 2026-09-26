//
// Created by ubril on 9/22/2026.
//

#include<iostream>
#include<memory>

using namespace std;


void xx() {
    constexpr size_t n = 5;
    allocator<string> alloc;
    auto const p = alloc.allocate(n);

    auto q = p;

    cout << "memory start:" << p << endl;

    string s;
    while (cin >> s && q != p + n) {
        allocator_traits<allocator<string>>::construct(alloc, q, s);
        cout << *q << ": "<< q << endl;
        ++q;
    }

    while (q != p) {
        --q;
        allocator_traits<allocator<string>>::destroy(alloc, q);
        cout << "memmory destroyed: " << q << endl;

    }

    alloc.deallocate(p, n);
}

int main() {
    xx();
    return 0;
    constexpr size_t n = 5;
    string *const p = new string[n];
    string s;

    string *q = p;
    while (cin >> s && q != p+n) {
        *q++ = s;
    }
    const size_t size = q - p;

    delete[] p;


    //return 0;

}