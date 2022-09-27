//
// Created by ivanivan on 9/27/22.
//

#ifndef INF224_BASECLASS_H
#define INF224_BASECLASS_H


#include <string>

using namespace std;

class BaseClass {

private:
    string pathname{};
    string name{};
public:
    BaseClass();

    BaseClass(string name, string pathname);

    // "const string &" permet de renvoyer une référence vers name, économisant une copie.
    const string &getName() const;

    void setName(string &name);

    const string &getPathname() const;

    void setPathname(string &pathname);

    virtual void print(std::ostream & output) const;

    virtual void display() const;
};


#endif //INF224_BASECLASS_H
