//
// Created by ubril on 10/2/2026.
//

#include <iostream>
#include<string>
int main()
{
    // int i=0;
    // std::cout << i << " " << ++i << std::endl;
    // int a = 1, b=2, c=3, d=4;
    // if (a != b  < c) {
    //     std::cout << "oh yh" << std::endl;
    // }
    // int *b;
    // char *a;
    // double *dp = reinterpret_cast<double*>(b);
    //
    // char *pc = "hello world";
    // std::string s(pc);
    // std::cout << s << std::endl;
    //
    //
    // int i = 9;
    // double d = 3.14;
    //
    // i = i * static_cast<int>(d);
    // std::cout << i << std::endl;

    int i; double d; const std::string *ps; char *pc; void *pv;

    //pv = static_cast<void *>(&ps);
    //i = static_cast<int>(*pc);
    pv = static_cast<double *>(&d);
    pc = static_cast<char*>(pv);

    std::cout << typeid(double);



}