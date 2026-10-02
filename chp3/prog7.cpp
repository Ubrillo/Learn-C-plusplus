//
// Created by ubril on 10/1/2026.
//

#include <iostream>
#include <cstring>
#include<string>
#include<vector>

int main()
{
    // std::string s;
    // const char *str = s.c_str();
    //
    // int arr[] = {0, 1, 2, 3, 4, 5};
    //
    // std::vector<int> ivec(std::begin(arr), std::end(arr));
    //
    //

    // int arr[3][4] = {1,2,3,4,5,6,7,8,9};
    //
    // for (auto &row: arr) {
    //     for (auto &col: row) {
    //         std::cout << col << std::endl;
    //     }
    // }

    // int ia[3][4] = {1,2,3,4,5,6,7,8,9};
    // for (auto p = std::begin(ia); p != std::end(ia); ++p) {
    //     for (auto q = std::begin(*p); q != std::end(*p); ++q) {
    //         std::cout << *q << std::endl;
    //     }
    // }

    int ia[3][4] = {{1,2,3,4},{5,6,7,8}, {9,10,11,12}};

    // for ( int (&row)[4]: ia) {
    //     for (int &col : row) {
    //         std::cout << col << std::endl;
    //     }
    // }

    // for (size_t i=0; i<3; i++) {
    //     for (size_t k=0; k<4; k++) {
    //         std::cout << ia[i][k] << std::endl;
    //     }
    // }

    // for (int (*p)[4] = std::begin(ia); p != std::end(ia); ++p) {
    //     for (int *q = std::begin(*p); q != std::end(*p); ++q) {
    //         std::cout << *q << std::endl;
    //     }
    // }

    // using int_array = int[4];
    // for (int_array *p = ia; p != ia + 3; ++p) {
    //     for (int *q = *p; q != *p + 4; ++q) {
    //         std::cout << *q << std::endl;
    //     }
    // }

    for (auto  row = std::begin(ia); row != std::end(ia); ++row) {
        for (auto col  = std::begin(*row); col != std::end(*row); ++col) {
            std::cout << *col << std::endl;
        }
    }

}