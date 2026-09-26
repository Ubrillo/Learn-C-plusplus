//
// Created by ubril on 9/15/2026.
//


#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int>ptr)
{
    cout << "process is working" <<endl;

    cout << ptr.use_count() << endl;
}

int main()
{
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p));
    //process(shared_ptr<int>(p.get()));


    // auto p  = new int();
    // auto sp = make_shared<int>();
    //
    // process(sp);
    //
    // cout << sp.use_count() << endl;
    //
    //

    
}
