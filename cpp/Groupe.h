//
// Created by ivanivan on 16/10/22.
//

#ifndef INF224_GROUPE_H
#define INF224_GROUPE_H

#include <list>
#include <iostream>
#include <utility>
#include <memory>
#include "Multimedia.h"

using namespace std;
typedef std::shared_ptr<Multimedia> MultimediaPtr;

/// \brief Groupe class, stores Multimedia objects in a list of shared smart pointers
/// \author Ivan Ivanov
class Groupe : public list<MultimediaPtr> {
private:
    string name;

public:
    // Destructor
    ~Groupe() {
        cout << "Groupe object " << name << " destroyed" << endl;

    }

    // Constructors
    Groupe() {
        name = "";
    }

    Groupe(string name) : name(std::move(name)) {}

    // Getters
    const string &getName() const {
        return name;
    }

    void setName(const string &newname) {
        Groupe::name = newname;
    }

    void play() {
        for (auto &multimedia: *this) {
            multimedia->play();
        }
    }

    void print(ostream &output) const {
        output << "Groupe{name:" << name << ", members:[";
        for (auto &multimedia: *this) {
            multimedia->print(output);
            output << ", ";
        }
        output << "]}";
    }
};


#endif //INF224_GROUPE_H
