//
// Created by ubril on 10/6/2026.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    string ss;

    if (argv) {
        while (*argv) {
            cout << *argv++;
        }
    }
    cout << argc << endl;
}