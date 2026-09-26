//
// Created by ubril on 9/23/2026.
//

#ifndef C_PROG10_H
#define C_PROG10_H

//
// Created by ubril on 9/12/2026.
//

#include <iostream>
#include<memory>
#include<vector>
using namespace std;

class StrBlob {
    public:
        typedef std::vector<std::string>::size_type size_type;

        StrBlob(): data(make_shared<vector<string>>()){}
        StrBlob(std::initializer_list<std::string> il):data(make_shared<vector<string>>(il)){}

        size_type size() const {
            return data->size();
        }
        bool empty() const {
            return data->empty();
        }

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

        auto begin() const {
            check(0, "begin on empty StrBlob");
            return data->begin();
        }
        auto end() const {
            check(0, "end on empty StrBlob");
            return data->end();
        }

    private:
        std::shared_ptr<std::vector<std::string>> data;

    void check(size_type i, const std::string &msg) const {
            if (i >= data->size()) {
                throw std::out_of_range(msg);
            }
        }

};

#endif //C_PROG10_H
