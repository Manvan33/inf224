//
// Created by ivanivan on 9/27/22.
//

#ifndef INF224_MULTIMEDIA_H
#define INF224_MULTIMEDIA_H


#include <string>

using namespace std;

class Multimedia {

private:
    string pathname{};
    string name{};
public:
    Multimedia();

    Multimedia(string name, string pathname);

    // "const string &" permet de renvoyer une référence vers name, économisant une copie.
    const string &getName() const;

    void setName(const string &name);

    const string &getPathname() const;

    void setPathname(const string &new_pathname);

    virtual void print(ostream & output) const;

    virtual void play() const = 0;
};


#endif //INF224_MULTIMEDIA_H
