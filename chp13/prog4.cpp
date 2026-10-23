//
// Created by ubril on 10/18/2026.
//

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class HasPtr {
public:
    HasPtr(const std::string& s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

    HasPtr(const HasPtr &p):
        ps(p.ps), i(p.i), use(p.use){++*use;}

    HasPtr& operator=(const HasPtr&);

    ~HasPtr();

    std::size_t getUse() const {
        return *use;
    }

private:
    std::string *ps;
    int i;
    std::size_t *use;

};


HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
  ++*rhs.use;
  if (--*use == 0) {
      delete ps;
      delete use;
  }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;

    cout <<"operator=(const HasPtr&)" << endl;

    return *this;
}

int main() {
    HasPtr hp("hello");
    HasPtr hp2;
    hp2 = hp;


    cout << hp.getUse() << endl;
    cout << hp2.getUse() << endl;
}