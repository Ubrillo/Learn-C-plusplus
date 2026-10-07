//
// Created by ubril on 10/6/2026.
//

#include <iostream>
#include<string>
#include<vector>

using namespace std;

bool is_emptyy(string &s) {
    return s.empty();
}

void toLowerCase(string &str) {
    for (char &c: str) {
        c = tolower(c);
    }
}

bool anyCaptital(const string &str) {
    for (auto &c : str) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}


class matrix;
bool compare(matrix &a, matrix &b);
vector<int>::iterator change_val(int, vector<int>::iterator);

int main() {
    // const string ss = "hi";
    // bool xx = is_emptyy(ss);
    // cout << xx << endl;

    string ss = "hi There";
    auto result = anyCaptital(ss);
    toLowerCase(ss);
    cout << ss << endl;

}