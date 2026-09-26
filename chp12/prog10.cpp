//
// Created by ubril on 9/23/2026.
//

#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include "prog10.h"

using namespace std;

class QueryResult;

class TextQuery {
    public:
        using line_no = pmr::vector<string>::size_type;
        TextQuery(ifstream&);
        QueryResult query(const string&) const;

    private:
        StrBlob file{};
        map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is)  {
    string text;
    while (getline(is, text)) {
        file.push_back(text);
        size_t n = file.size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];

            if (!lines) {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}

class QueryResult {
    friend ostream &print(ostream &, const QueryResult &);
    private:
        using line_no = pmr::vector<string>::size_type;
        string sought;
        shared_ptr<set<line_no>> lines;
        const StrBlob &file{};

    public:
        QueryResult(string s, shared_ptr<set<line_no>> p,
            const StrBlob &f) : sought(s), lines(p), file(f){}

        auto get_file() const -> const StrBlob& {
            return file;
        }
};

QueryResult TextQuery::query(const string &sought)const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file); //not found
    }else {
        return QueryResult(sought, loc->second, file);
    }
}

string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
    << make_plural(qr.lines->size(), "time", "s") << endl;

    for (auto num: *qr.lines) {
        os << "\t(line " << num+1 << ") " << *(qr.file.begin() + num) << endl;
    }
    return os;
}

int main() {


    ifstream file("scratch");
    if (!file) {
        cout << "oops!!" << endl;
        cerr << "Unable to open file" << endl;
    }else {

        TextQuery index(file);
        //string text = ;
        QueryResult qr(index.query("learn"));
        print(cout, qr);
    }

}