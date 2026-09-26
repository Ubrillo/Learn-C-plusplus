//
// Created by ubril on 9/25/2026.
//

#include <vector>
#include <string>
#include <iostream>

using std::string;
using  std::vector;
using std::cout;
using std::endl;
using std::cin;

int main () {
    //exercise 3.16
    // vector <string> words;
    // string s;
    // while (cin >> s) {
    //     words.push_back(s);
    // }
    //
    // for (auto &word: words) {
    //     for (auto &c: word) {
    //         c = toupper(c);
    //     }
    // }
    // //cout << words.size() << endl;
    // for (auto word: words) {
    //     cout << word << " ";
    // }

    /**exercise 3.16 **/
    vector <int> ivec{0,1,2,3,4,5,6,7,8,9};

    //vector<string>::size_type index = 0;
    decltype(ivec.size()) x;
    decltype(ivec.size()) y;
    x = 0;
    y = ivec.size()-1;
    while (x < y) {
        cout << ivec[x] + ivec[y]<< endl;
        ++x;
        --y;
    }

}