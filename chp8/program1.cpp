//
// Created by ubril on 6/2/2026.
//

#include<cstdio>

class Tracer {

    private:
        const char* const name;

    public:
        Tracer(const char *name):name(name) {
            printf("%s constructed.\n", name);
        }
        ~Tracer() {
            printf("%s destructed.\n", name);
        }
};


int main()
{
    Tracer main{"main"};
    {
        printf("Block a\n");
        Tracer a1{ "a1" };
        Tracer a2{ "a2" };
    }
    {
        printf("Block b\n");
        Tracer b1{ "b1" };
        Tracer b2{ "b2" };
    }
}