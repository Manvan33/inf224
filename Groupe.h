//
// Created by manvan on 16/10/22.
//

#ifndef INF224_GROUPE_H
#define INF224_GROUPE_H

#include <list>
#include "Multimedia.h"

using namespace std;

class Groupe : list<Multimedia>{
private:
    string name;
// Constructor
public:
    Groupe() = default;

    Groupe(const string &name) : name(name) {}

    // Destructor
    ~Groupe() = default;

    // Getters
    const string &getName() const {
        return name;
    }

    // Setters
    void setName(const string &name) {
        Groupe::name = name;
    }

    // Methods
    void add(Multimedia *multimedia) {
        push_back(multimedia);
    }

    void remove(Multimedia *multimedia) {
        remove(multimedia);
    }

    void play() {
        for (auto &multimedia : *this) {
            multimedia.play();
        }
    }

    void print(ostream &output) const {
        output << "Groupe{" << endl;
        for (auto &multimedia : *this) {
            multimedia.print(output);
        }
        output << "}" << endl;
    }
};


#endif //INF224_GROUPE_H
