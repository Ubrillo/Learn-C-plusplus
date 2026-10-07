//
// Created by ubril on 10/5/2026.
//


#include <iostream>
#include <string>
using namespace std;


int main() {

    int a, b;

    while (cin >> a >> b) {
        try {
            int c;
            (b == 0) ? throw runtime_error("b is zero") : c = a/b;
            cout << c << endl;
        }catch(runtime_error err) {
            cout << err.what() << "\n try again" << endl;

        }
    }

}