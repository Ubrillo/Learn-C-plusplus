//
// Created by ubril on 10/11/2026.
//

#include <iostream>
#include <string>
#include <vector>

class NoDefault {
    public:
    NoDefault(const std::string&);
    
};

struct A {
    NoDefault my_mem;
};

struct B {
    B(){}
    //NoDefault b_member;
};

struct C {

    C () : c_member(""){}
    NoDefault c_member;
};

//std::vector<NoDefault> vec(10);


struct Data {
    int val;
    std::string s;
};

Data v1 = {1, "hi"};


class Account {
    public:
        void calculate(){amount += amount * interestRate;}
        static double rate() {return interestRate;}
        static void rate(double);

    private:
        std::string owner;
        double amount;
        static double interestRate;
        static double initRate();
};
double Account::interestRate = initRate();

void Account::rate(double newRate) {
    interestRate = newRate;
}

class Screen {
    public:
        Screen& clear(char = bkground);
    private:
        static const char bkground;
};


int main() {
    
}




