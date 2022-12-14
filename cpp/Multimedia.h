//
// Created by ivanivan on 9/27/22.
//

#ifndef INF224_MULTIMEDIA_H
#define INF224_MULTIMEDIA_H


#include <string>

using namespace std;

/// \brief Multimedia class
/// \details Multimedia is a base class for all multimedia objects.
/// \author Ivan Ivanov
class Multimedia {

private:
    string pathname{};
    string name{};
public:
    Multimedia();

    Multimedia(string name, string pathname);

    virtual ~Multimedia();

    // "const string &" permet de renvoyer une référence vers name, économisant une copie.
    const string &getName() const;

    void setName(const string &name);

    const string &getPathname() const;

    void setPathname(const string &new_pathname);

    virtual void print(ostream &output) const;

    virtual void play() const = 0;
};


#endif //INF224_MULTIMEDIA_H
