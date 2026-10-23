//
// Created by ubril on 10/20/2026.
//

#ifndef C_PROG9_H
#define C_PROG9_H

#include <iostream>
#include<memory>
#include<vector>

#include <string>

#include "prog9.h"
using  std::string;
using std::allocator;
using std::make_shared;
using std::vector;


class StrVec {
    friend class StrBlob;
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

inline void StrVec::push_back(const string &s)
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

inline void StrVec::free() {
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

inline void StrVec::reallocate() {
    auto newcapacity =  size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i=0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}


inline StrVec::StrVec(std::initializer_list<string> il):
    elements(nullptr), first_free(nullptr), cap(nullptr)
{
    for (auto &s: il) {
        push_back(s);
    }
}

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob(): data(make_shared<StrVec>()){}
    StrBlob(std::initializer_list<string> il):data(make_shared<StrVec>(il)){}

    size_type size() const {
        return data->size();
    }

    bool empty() const {
        return size() == 0 ? true : false;
    }

    void push_back(const std::string &t) const{
        data->push_back(t);
    }
    // void pop_back() const{
    //     check(0, "pop_back on empty StrBlob");
    //     return data->pop_back();
    // }

    // std::string& front() const {
    //     check(0, "front on empty StrBlob");
    //     return data->front();
    // }

    // std:: string& back() const {
    //     check(0, "back on empty StrBlob");
    //     return data->back();
    // }

    string* begin() const {
        check(0, "begin on empty StrBlob");
        return data->elements;
    }
    // vector<string>::iterator end() const {
    //     check(0, "end on empty StrBlob");
    //     return data->end();
    // }

private:
    std::shared_ptr<StrVec> data;

    void check(size_type i, const string &msg) const {
        if (i >= data->size()) {
            throw std::out_of_range(msg);
        }
    }

};


#endif //C_PROG9_H
