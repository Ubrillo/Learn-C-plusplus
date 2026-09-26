//
// Created by ubril on 6/2/2026.
//

#include <cstdio>

namespace Fruits::Apple {

    enum class Color {
        Pink,
        Red,
        Yellow
    };

    class properties {

        public:
            const char *name;
            Color color;
    };

    bool trysomething(const properties &p) {
        return p.color == Color::Pink;
    }
}
using apple_color =  Fruits::Apple::Color;
using String = const char[260];



int main() {
    const auto my_color {apple_color::Pink};
    String saying{"text"};

    if (my_color == apple_color::Pink) {
        printf("%s\n", saying);
    }
}