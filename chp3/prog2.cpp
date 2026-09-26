//
// Created by ubril on 9/25/2026.
//


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // string s("some string");
    //
    // if (s.begin() != s.end()) {
    //     auto it = s.begin();
    //     *it = toupper(*it);
    //
    // }
    //
    // for (auto itr = s.begin(); itr != s.end(); ++itr) {
    //     *itr = toupper(*itr);
    // }
    //
    // string text("writings shshshs");
    //
    // for (auto itr = text.cbegin(); itr != text.cend(); ++itr) {
    //     cout << *itr;
    // }

    /* exercise 3.22 */
    // vector<string> svec{"hello world", "", "i love it!"};
    //
    // for (auto itr = svec.begin();
    //     itr != svec.end() && !itr->empty();
    //     ++itr) {
    //
    //     for (auto it = itr->begin(); it != itr->end(); ++it) {
    //         *it = toupper(*it);
    //     }
    //
    // }
    // for (auto it = svec.cbegin(); it != svec.cend(); ++it) {
    //     cout << *it << " ";
    // }

    /*exercise 3.2.3 */
    vector<int> ivec{1,2,3,4,5,6,7,8,9,0};
    for (auto itr = ivec.begin(); itr != ivec.end(); ++itr) {
        *itr *= *itr;
    }

    for (auto itr = ivec.cbegin(); itr != ivec.cend(); ++itr) {
        cout << *itr << endl;
    }

}