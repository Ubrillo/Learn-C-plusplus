//
// Created by ubril on 9/20/2026.
//

#include <cstring>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

void readString() {
    size_t size;
    cout << "enter array size: ";
    cin >> size;

    char* str = new char[size];

    cout << "enter a string";

    cin >> str;

    cout << "you entered: " << str << '\n';
    delete[] str;

}

int main() {

    const char *s1 = "hello ";
    const char *s2 = "world";

    char *result = new char[strlen(s1)+strlen(s2)+1];

    strcpy(result,s1);
    strcat(result,s2);

    cout << result << '\n';

    delete[] result;

    string a = "hello ";
    string b = "world";

    string answer = a + b;
    cout << answer <<endl;

    return 0;
}

