//
// Created by ubril on 10/8/2026.
//
#include<iostream>
#include<string>
using namespace std;

string make_plural(size_t ctr,
     const string &word,
     const string &ending="s") {

    return (ctr > 1) ? word + ending : word;
}


int a = 1;
int b = 2;
string c = "hi";

void screen(int d = a, int e=b, string f = c) {
    cout << a << b << c << endl;
}

void f2() {
    a = 3;
    b = 4;
    string c = "hello";
    screen();
}

int main() {
    //cout << make_plural(3,  "success", "es") << endl;
    screen();
    f2();
}
