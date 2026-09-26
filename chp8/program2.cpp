//
// Created by ubril on 6/2/2026.
//


#include <cstdint>
#include <cstdio>

class RandomNumberGenerator {
    private:
        size_t iterations;
        uint32_t number;

    public:
        explicit RandomNumberGenerator(size_t seed) : iterations{}, number{seed}{}

        uint32_t next();
        size_t get_iterations() const;
};

int main() {
    RandomNumberGenerator rng{ 0x4c4347};
    while (rng.next() !=  0x474343){

    }
    printf("%zd", rng.get_iterations());
}

uint32_t RandomNumberGenerator::next() {
    ++iterations;
    number =  0x3FFFFFFF & (0x41C64E6D * number + 12345) % 0x80000000;
    return number;
}

size_t RandomNumberGenerator::get_iterations() const {
    return iterations;
}