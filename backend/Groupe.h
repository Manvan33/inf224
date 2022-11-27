//
// Created by ivanivan on 16/10/22.
//

#ifndef INF224_GROUPE_H
#define INF224_GROUPE_H

#include <list>
#include <iostream>
#include <utility>
#include "Multimedia.h"

using namespace std;

class Groupe : public list<Multimedia *>{
private:
    string name;

public:
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
        for (auto &multimedia : *this) {
            multimedia->play();
        }
    }

    void print(ostream & output) const {
        output << "Groupe{ name:" << name << ", members:" << endl;
        for (auto &multimedia : *this) {
            output << "\t- ";
            multimedia->print(output);
        }
        output << "}" << endl;
    }
};


#endif //INF224_GROUPE_H
