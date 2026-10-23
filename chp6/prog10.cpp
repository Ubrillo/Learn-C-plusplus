//
// Created by ubril on 10/8/2026.
//

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int calc(int&, int&);
int calc(const int&, const int&);

int calc(char*, char*);
int calc(const char*, const char*);

int calc(char*, char*);
int calc(char* const, char* const);


bool (*pf)(const string&, const string&);
bool lengthCompare(const string&, const string&);



int fnc(int, int);

int  add(int a, int b) {
   return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int  multiply(int a, int b) {
    return a * b;
}
int divide(int a, int b) {
    return a / b;

}

int main() {
    //using PF =  int (*)(int, int);
    using PF = decltype(fnc)*;
    //typedef decltype(fnc) *PF; // int(*)(int, int)

    PF fpAdd = add;
    PF fpSubtract = subtract;
    PF fpMultiply = multiply;
    PF fpDivide = divide;

    vector<PF> vpf;
    vpf.push_back(fpAdd);
    vpf.push_back(fpSubtract);
    vpf.push_back(fpMultiply);
    vpf.push_back(fpDivide);

    for (PF pf: vpf) {
        cout << (pf)(10, 5) << endl;;
    }
}