//
// Created by ubril on 10/22/2026.
//


#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr; //Not applicable in this program, used in prog6.cpp

    friend bool operator==(const StrBlob&, const StrBlob&);

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

    StrBlobPtr begin() const ;
    StrBlobPtr end() const;

private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_type i, const std::string &msg) const {
        if (i >= data->size()) {
            throw std::out_of_range(msg);
        }
    }

};

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
private:
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

StrBlobPtr StrBlob::begin() const {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() const {
    return StrBlobPtr(*this, data->size());
}


bool operator==(const StrBlob& lhs, const StrBlob& rhs) {
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs) {
    return !(lhs == rhs);
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return lhs.wptr.lock() == rhs.wptr.lock() &&
        lhs.curr == rhs.curr;
}


int main() {
    string text;

    const StrBlob blob1({"abc", "def", "ghi"});
    const StrBlob blob2({"abc", "def", "ghi"});

    StrBlobPtr bp1(blob1.begin());
    StrBlobPtr bp2 = StrBlobPtr(blob1.begin());


    // cout << "PRINTING BLOB TEXT" << endl;
    //
    // while (1) {
    //     cout << bp.deref() << endl;
    //     bp.incr();
    // }

    cout << static_cast<int>(bp1 == bp2) << endl;

}