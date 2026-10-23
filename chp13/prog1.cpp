//
// Created by ubril on 10/16/2026.
//
#include <iostream>
#include <string>
#include <vector>


class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }

    HasPtr(const HasPtr &hp): ps(new std::string(*hp.ps)), i(hp.i) { }

    HasPtr& operator=(const HasPtr& rhs) {
        ps = new std::string(*rhs.ps);
        int i = rhs.i;
        return *this;
    }
    ~HasPtr() {}

private:
    std::string *ps;
    int i;
};



struct Tester {
    Tester(){std::cout << "Tester()" << std::endl;}
    Tester(const Tester &t){std::cout << "Tester(const Tester&)" << std::endl;}
    Tester& operator=(const Tester &t) {
        std::cout << "Tester op=(const Tester&)" << std::endl;
        return *this;
    }
    ~Tester(){std::cout << "~Tester()" << std::endl;}
};

void func(const Tester &t) {

}

void func2(const Tester t) {

}



class Numbered {
public:
    Numbered() = default;

private:
    //int mysn = random();

};



int main() {
    Tester t;
    //func2(t);
    // std::vector <Tester> vec;
    // vec.push_back(t);
    // vec.push_back(t2);
    //t = t2;
    //Tester *t3 = new Tester();
    //delete t3;
    //Tester t2;
}