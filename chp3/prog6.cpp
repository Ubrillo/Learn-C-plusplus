//
// Created by ubril on 10/1/2026.
//

#include <iostream>
#include <cstring>

int main() {
    const char a[] = "hello";
    const char b[] = "hello";

    if (strcmp(a, b) == 0) {
        std::cout << "same" << std::endl;
    }
    else {
        std::cout << "not same" << std::endl;
    }

    const char c[] = "hello";
    const char d[] = "word";

    const size_t n = strlen(c) + strlen(d) + 11;
    char f[n+1];

    strcpy(f, c);
    strcat(f, " ");
    strcat(f, d);

    const char *p = f;

    while (*p) {
        std::cout << *p++ << std::endl;
    }

    std::cout << strlen(f) << std::endl;
}