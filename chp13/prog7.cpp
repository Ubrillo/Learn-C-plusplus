//
// Created by ubril on 10/19/2026.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

class Message;

class Folder {
    friend void swap(Folder &lhs, Folder &rhs);
    friend void print();
public:
    explicit Folder(std::string name = ""):name(name){}
    Folder(const Folder&);
    Folder& operator=(const Folder&);

    ~Folder(){messages.clear();};

    void addMsg(Message*);
    void remMsg(Message*);

private:
    std::set<Message*> messages;
    std::string name;
};

void Folder::addMsg(Message* m)
{
    messages.insert(m);
}

void Folder::remMsg(Message* m)
{
    messages.erase(m);
}

Folder::Folder(const Folder& f):
    name(f.name), messages(f.messages){}

Folder& Folder::operator=(const Folder& rhs)
{
    name = rhs.name;
    messages = rhs.messages;
    return *this;
}

void swap(Folder &lhs, Folder &rhs)
{
    swap(lhs.name, rhs.name);
    swap(lhs.messages, rhs.messages);
}


class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
    friend void print();
public:
    explicit Message(const std::string &str = ""):
        contents(str){}

    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    void save(Folder&);
    void remove(Folder&);

private:
    std::string contents;
    std::set<Folder*>folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
    for (auto f: m.folders) {
        f->addMsg(this);
    }
}

Message::Message(const Message& m):
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for (auto f: folders) {
        f->remMsg(this);
    }
    folders.clear();
}

Message::~Message()
{
    remove_from_Folders();
}

Message& Message::operator=(const Message& rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f: lhs.folders)
        f->remMsg(&lhs);

    for (auto f: rhs.folders)
        f->remMsg(&rhs);

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto f: lhs.folders)
        f->addMsg(&lhs);

    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}

void print()
{
    Folder f1,f2,f3;
    Message m1("hello world");

    m1.save(f1);
    m1.save(f2);

    m1.contents = "hi there!";
    //f3 = f2;

    std::cout << (*f1.messages.begin())->contents << std::endl;
}

int main()
{
    print();

}