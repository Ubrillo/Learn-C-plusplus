//
// Created by ubril on 10/21/2026.
//

#include <iostream>
#include<memory>
#include<vector>

using  std::string;
using std::allocator;
using std::make_shared;
using std::vector;

class String {
public:
    String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char*); // pointer to c-style string
    String(const String&);
    String& operator=(const String&);
    ~String();
    void push_back(const char&);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    char *begin() const {return elements;}
    char *end() const {return first_free;}

    void print() const;

    void push_back(const char* cptr);
    String (String&&) noexcept;

private:
    static allocator<char> alloc;
    void chk_n_alloc() {if (size() == capacity()) reallocate();}
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();
    void reallocate();
    char *elements;
    char *first_free;
    char* cap;
};
allocator<char> String::alloc;

String::String(const char* cptr):elements(nullptr), first_free(nullptr), cap(nullptr) {
    while (*cptr) {
        push_back(*cptr++);
    }
}

void String::push_back(const char& ch) {
    chk_n_alloc();
    alloc.construct(first_free++, ch);
}

void String::push_back(const char* cptr) {
    while (*cptr)
        push_back(*cptr++);
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void String::free() {
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

String::String(const String& s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
    std::cout <<"copy constructor"<<std::endl;
}
String::~String() {free();}

String& String::operator=(const String &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;

    std::cout <<"copy assignment"<<std::endl;
    return *this;
}

void String::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i < size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void String::print() const {
    const char *p = elements;
    while (p != first_free) {
        std::cout <<*p++;
    }
}

String::String(String&& s) noexcept :
elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
    std::cout <<"move constructor"<<std::endl;
}


int main() {
    // String abc;
    // abc.push_back('a');
    // abc.push_back('b');
    // abc.push_back('c');
    //
    // String ss("book");
    // ss = abc;
    // ss.print();
    //
    // char ca[] = {'a', 'b', 'c', '\0'};
    // String op(ca);
    //
    //
    // op.push_back("2");
    // op.print();

    vector<String> vec1;
    vec1.push_back("1");
    vec1.push_back("2");
    vec1.push_back("2");

}