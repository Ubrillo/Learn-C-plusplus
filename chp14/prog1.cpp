//
// Created by ubril on 10/22/2026.
//


#include<iostream>
#include<string>
//using namespace std;
using std::istream;
using std::ostream;

class Sales_data {
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);

    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend istream& operator>>(istream&, Sales_data&);
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend bool operator!=(const Sales_data&, const Sales_data&);

public:

    Sales_data() : Sales_data("", 0, 0) {
        std::cout << "Sales_data::default construtor" << std::endl;
    }

    explicit Sales_data(const std::string& s):Sales_data(s,0 ,0){}

    Sales_data(const std::string& s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) {
        std::cout << "Sales_data::3 args constructor" << std::endl;
    }

    explicit Sales_data(std::istream& is) : Sales_data() {
        std::cout << "Sales_data::istream constructor" << std::endl;
        read(is, *this);
    }

    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const {return units_sold ? revenue / units_sold : 0;}
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
std::istream &read(std::istream&, Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream& read(std::istream& is, Sales_data& item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();

    return os;
}

istream& operator>>(istream& is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();

    return is;
}

Sales_data
operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data  sum = lhs;
    sum += rhs;
    return sum;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn() &&
        lhs.units_sold == rhs.units_sold &&
            lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}



int main() {
    Sales_data item1("a", 1.0, 2.0);
    Sales_data item2("b", 2.0, 3.0);

    std::cin >> item1;
    std::cout << item1;


}