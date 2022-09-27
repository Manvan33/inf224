//
// Created by ivanivan on 9/27/22.
//

#ifndef INF224_MYCLASS_H
#define INF224_MYCLASS_H


#include <string>

using namespace std;

class MyClass {
private:
    string name{};
    string pathname{};

public:
    MyClass();

    MyClass(string name, string pathname);

    // "const string &" permet de renvoyer une référence vers name, économisant une copie.
    const string &getName() const;

    void setName(string &name);

    const string &getPathname() const;

    void setPathname(string &pathname);
};


#endif //INF224_MYCLASS_H
