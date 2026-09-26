//
// Created by ubril on 9/16/2026.
//
#include <iostream>
#include<memory>
using namespace std;

struct destination {
    string endpoint  = "0.0.0.0";
};

struct connection {
    string processID = "123";
    destination endpoint;
};

connection* connect(destination*)
{
    //shared_ptr<connection> con(new connection{"001", "0.0.0.1"});
    connection* con = new connection{"001", "0.0.0.1"};

    return con;
}

void end_connection(connection *&con) {

}

auto  kill = [](connection *&con) {
    delete con;
    con = nullptr;
};

void user (destination &destination) {
    connection *con = connect(&destination);
    shared_ptr<connection> p (con,[](connection *&con){delete con;});

    cout << "connection established!!" << endl;
    cout << con->processID << endl << con->endpoint.endpoint << endl;
}

void disconnect(connection *con) {
    con = nullptr;
}

// void end_connection(connection *p) {
//     disconnect(p);
//     cout<<"end"<<endl;
// }

int main()
{
    destination dest1;
    user(dest1);
    //connection com1 = connect(&dest1);


    //void disconnect(connection);

    //std::shared_ptr<connection> p (&c, [](){});

}
