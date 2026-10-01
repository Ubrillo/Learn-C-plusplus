//
// Created by ubril on 9/29/2026.
//

#include <iostream>
#include <string>
#include <vector>


int  text_size() {
    return 1;
}

int main() {
    constexpr size_t size = 10;
    int a[size] = {1,2,3,4,5,6,7,8,9,10};
    int b[size] = {};

    for (size_t i = 0; i < size; i++) {
        b[i] = a[i];
    }

    for (auto i : b) {
        std::cout << i << " ";
    }

    std::vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> v2(10, 0);
    v1 = v2;

}