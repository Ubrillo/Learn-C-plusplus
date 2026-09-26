//
// Created by ubril on 9/18/2026.
//


#include <iostream>
#include <memory>
#include <vector>
using namespace std;



class StrBlob {
    friend class StrBlobPtr; //Not applicable in this program, used in prog6.cpp

public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob(): data(make_shared<vector<string>>()){}
    StrBlob(std::initializer_list<std::string> il):data(make_shared<vector<string>>(il)){}

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    void push_back(const std::string &t) const{
        data->push_back(t);
    }
    void pop_back() const{
        check(0, "pop_back on empty StrBlob");
        return data->pop_back();
    }

    std::string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    std:: string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();

    }

    auto begin() const;
    auto end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const {
        if (i >= data->size()) {
            throw std::out_of_range(msg);
        }
    }

};

class StrBlobPtr {
    weak_ptr<vector<string>>wptr;
    size_t curr;

    shared_ptr<vector<string>> check(size_t i, const string &msg) const {
        auto ret = wptr.lock();
        if (!ret) {
            throw runtime_error("unbonund StrBlobPtr");
        }
        if (i >= ret->size()) {
            throw out_of_range(msg);
        }
        return ret;
    }

public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(const StrBlob &blob, size_t sz = 0): wptr(blob.data), curr(sz) {}

    string& deref() const {
        auto p  = check(curr, "deference past end");
        return (*p)[curr];
    }

    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
};

auto StrBlob::begin() const {
    return StrBlobPtr(*this);
}

auto StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

int main() {
    string text;

    const StrBlob blob({"abc", "def", "ghi"});

    StrBlobPtr bp(blob.begin());
    cout << "PRINTING BLOB TEXT" << endl;

    while (1) {
        cout << bp.deref() << endl;
        bp.incr();
    }
        // auto p = make_shared<int>(42);
    // weak_ptr<int> wp(p);
    //
    // if (shared_ptr<int> np = wp.lock()) {
    //     cout << *np << endl;
    // }
}