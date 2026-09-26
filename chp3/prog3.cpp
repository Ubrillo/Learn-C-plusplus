//
// Created by ubril on 9/26/2026.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    /*exercise 3.24*/
    // vector <int> ivec{0,1,2,3,4,5,6,7,8,9};
    //
    // //vector<string>::size_type index = 0;
    // auto ib = ivec.begin();
    // auto ie = ivec.end()-1;
    //
    // while (ib < ie) {
    //     cout << *ib + *ie<< endl;
    //     ++ib;
    //     --ie;
    // }



    //exercise 3.25
    vector<int> grades(11, 0);
    int value;
    while (cin  >> value) {
        if (value <= 100) {
            auto it = grades.begin() + value/10;
            (*it)++;
        }
    }
    for (auto it = grades.begin(); it != grades.end(); ++it) {
        cout << *it << " ";
    }
}