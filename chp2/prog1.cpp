//
// Created by ubril on 9/25/2026.
//




#include<string>
#include<iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {

    string str("some string!!!");

    decltype(str.size()) punct_cnt = 0;

    for (auto c : str) {
        if (ispunct(c)) {
            ++punct_cnt;
        }
    }
    cout << punct_cnt << " punctutation xters in " << str << endl;

    string s("Hello World!!!");

    for (auto &c: s)
        c = toupper(c);
    cout << s << endl;

    if (!s.empty()) {
        s[0] = toupper(s[0]);
    }



    for (decltype(str.size()) i = 0;
        i <= str.size() && !isspace(s[i]); ++i) {
        s[i] = toupper(s[i]);
    }

    string::size_type n;

    string
}