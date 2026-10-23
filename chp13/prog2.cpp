//
// Created by ubril on 10/17/2026.
//

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
public:

    HasPtr(const std::string& s = std::string()):
        ps(new std::string(s)), i(0) {}

    HasPtr(const HasPtr& p):
        ps(new std::string(*p.ps)), i(p.i){}

    HasPtr& operator=(const HasPtr &);



    ~HasPtr() {delete ps;}

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



int main() {
    Employee job;
    Employee jack;

    f(jack);
    std::cout << job.id << std::endl;
    std::cout << jack.id << std::endl;
}