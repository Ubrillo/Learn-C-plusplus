//
// Created by ubril on 10/19/2026.
//

//
// Created by ubril on 10/17/2026.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Employee {

public:
    //Employee() = default;
    Employee() {
        id++;
    }
    Employee(std::string name): name(name) {
        id++;
    }
    static int id;

private:
    std::string name;

};

int Employee::id = 0;

void f(Employee e) {
    std::cout << e.id << std::endl;
}


class HasPtr {
    friend void tester(HasPtr&);
public:

    HasPtr(const std::string& s = std::string()):
        ps(new std::string(s)), i(0) {}

    HasPtr(const HasPtr& p):
        ps(new std::string(*p.ps)), i(p.i){}

    HasPtr& operator=(const HasPtr &);

    HasPtr& operator=(HasPtr &);

    HasPtr& operator<(const HasPtr&);


    inline void swap(HasPtr &lhs, HasPtr &rhs) {
        using std::swap;
        swap(lhs.ps, rhs.ps);
        swap(lhs.i, rhs.i);
    }

    ~HasPtr() {delete ps;}

    HasPtr(HasPtr &&p) noexcept: ps(p.ps), i(p.i) {p.ps = 0;}

    HasPtr& operator=(HasPtr rhs){swap(*this, rhs); return *this;}

private:
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;

    return *this;
}


HasPtr& HasPtr::operator=(HasPtr &rhs) {
    swap(*this, rhs);

    std::cout << "swap operator called" << std::endl;
    return *this;
}


HasPtr& HasPtr::operator<(const HasPtr &rhs) {

}


void tester(HasPtr& ptr) {
    std::cout << *ptr.ps << std::endl;
}

int main() {
    // Employee job;
    // Employee jack;
    //
    // f(jack);
    // std::cout << job.id << std::endl;
    // std::cout << jack.id << std::endl;

    HasPtr hp("hello");
    HasPtr hp2;
    hp2 = hp;
    tester(hp2);

    HasPtr x, y;
    std::vector<HasPtr>hpo = {x, y};
    // std::sort(hpo.begin(), hpo.end(),   [x,y]() {
    //     return x.i < y.i
    // });
}
