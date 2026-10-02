//
// Created by ubril on 10/1/2026.
//


#include <vector>
#include <iostream>

int main()
{
    //exercise 3.35
    int a[10];
    int *start = std::begin(a);
    int *end = std::end(a);

    while (start != end) {
        *start++ = 0;

    }
    for (auto i:a) {
        std::cout << i << std::endl;
    }

    //
}

