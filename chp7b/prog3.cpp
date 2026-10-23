//
// Created by ubril on 10/11/2026.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef string Type;
Type initVal();

class Exercise {

public:
    typedef double TypeB;
    TypeB setVal(TypeB);
    TypeB initVal();

private:
    int val;

};

Exercise::TypeB Exercise::setVal(TypeB parm) {
    val = parm + initVal();
    return val;
}

int main(){}