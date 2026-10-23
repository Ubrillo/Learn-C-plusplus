//
// Created by ubril on 10/22/2026.
//


#include <iostream>
#include <string>
using  std::string;
using std::allocator;
#include<memory>

class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);

public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    ~StrVec();
    void push_back(const std::string&);
    std::size_t size() const {return first_free - elements;}
    std::size_t capacity() const {return cap - elements;}
    std::string* begin() const {return elements;}
    std::string* end() const {return first_free;}

    StrVec(std::initializer_list<string>);

    std::string& front() const {
        if (elements)
            return *elements;
    }

    StrVec(StrVec&&);

private:
    static std::allocator<string> alloc;
    void chk_n_alloc(){if (size()==capacity()) reallocate();}
    std::pair<string*, string*> alloc_n_copy (const string*, const string*);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

allocator<string> StrVec::alloc;

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair <string*, string*>
    StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e-b);
    return {data, std::uninitialized_copy(b,e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p=first_free; p!=elements; ) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap-elements);
    }
}

StrVec::StrVec(const StrVec& s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap =  newdata.second;
}

StrVec::~StrVec(){free();}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto  data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity =  size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);

    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);

    // auto dest = newdata;
    // auto elem = elements;
    // for (size_t i=0; i != size(); ++i) {
    //     alloc.construct(dest++, std::move(*elem++));
    // }
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}


StrVec::StrVec(std::initializer_list<string> il):
    elements(nullptr), first_free(nullptr), cap(nullptr)
{
    for (auto &s: il) {
        push_back(s);
    }
}

bool operator==(const StrVec& lhs, const StrVec& rhs) {
    const string* lps = lhs.begin();
    const string* rps = rhs.begin();

    if (lhs.size() != rhs.size())
        return false;

    while (lps != lhs.end() && rps != rhs.end()) {
        if (*lps++ != *rps++) {
            return false;
        }
    }
    return true;
}

bool operator!=(const StrVec& lhs, const StrVec& rhs) {
    return !(lhs == rhs);
}


int main() {
    StrVec vec, vec2;
    vec.push_back("1");
    //vec2.push_back("1");

    // vec.push_back("abc");
    // vec.push_back("def");
    //
    // vec2.push_back("abc");
    // vec2.push_back("df");

    std::cout << static_cast<int>(vec == vec2) << std::endl;
}