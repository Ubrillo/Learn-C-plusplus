//
// Created by ubril on 10/17/2026.
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

    StrBlob(const StrBlob&);

    StrBlob &operator=(const StrBlob&);

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

StrBlob::StrBlob(const StrBlob &sBlob):
    data(make_shared<vector<string>>(*sBlob.data)) {
    cout << "copy version" << endl;
}

StrBlob& StrBlob::operator=(const StrBlob &rhs) {
    auto newptr = make_shared<vector<string>>(*rhs.data);
    data.reset();
    data = newptr;
    cout <<"operator copy"<<endl;
    return *this;
}

void tester(StrBlob sb) {
    sb.push_back("cheese");
    cout << sb.size() << endl;
}


using namespace std;

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

int main(){
    //StrBlob b1({"hi", "there"});
    //StrBlob b2 = b1;
    //tester(b1);
    // cout << b1.size() << endl;
    // b2.push_back("choppy");
    // cout << b2.size() << endl;

    string text;
    const StrBlob blob({"abc", "def", "ghi"});

    StrBlobPtr bp(blob.begin());
    cout << "PRINTING BLOB TEXT" << endl;

    while (1) {
        cout << bp.deref() << endl;
        bp.incr();
    }
}
