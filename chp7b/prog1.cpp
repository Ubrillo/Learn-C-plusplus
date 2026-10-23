//
// Created by ubril on 10/9/2026.
//

#include<iostream>
#include<string>
//using namespace std;

class Sales_data {
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);
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

// struct Person;
// std::istream& read(std::istream& is, Person& person);
//
// struct Person {
//     Person() = default;
//     Person(std::string name, std::string address=""): name(name), address(address) {}
//
//     Person(std::istream& is) {
//         read(is, *this);
//     }
//     std::string name;
//     std::string address;
//     std::string getName() const {return name;}
//     std::string getAddress() const {return address;}
// };
//
// std::istream& read(std::istream& is, Person& person) {
//     std::string name;
//     std::string address;
//     is >> name >> address;
//     person.name = name;
//     person.address = address;
//     return is;
// }
//
// std::ostream& print(std::ostream& os, const Person& person) {
//     os << person.name << " " << person.address;
//     return os;
// }

int main() {
    // Person p1, p2;
    // read(read(std::cin, p1), p2);
    // print(print(std::cout, p1),  p2);

    //Sales_data item(std::cin);
    //print(std::cout, item);

    std::string null_book = "9-0-00-0";
    // Sales_data item(null_book);
    // item.combine(null_book);

    Sales_data item2 = null_book;
    print(std::cout, item2);


}