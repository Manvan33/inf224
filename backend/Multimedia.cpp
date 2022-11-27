//
// Created by ivanivan on 9/27/22.
//

#include <cstring>
#include <iostream>
#include "Multimedia.h"

using namespace std;

Multimedia::Multimedia() = default;

Multimedia::Multimedia(string name, string pathname) {
    setName(name);
    setPathname(pathname);
}

void Multimedia::setName(const string &new_name) {
    Multimedia::name = new_name;
}


void Multimedia::setPathname(const string &new_pathname) {
    Multimedia::pathname = new_pathname;
}


const string &Multimedia::getPathname() const {
    return pathname;
}

const string &Multimedia::getName() const {
    return name;
}

void Multimedia::print(ostream & output) const {
    output << "Multimedia{pathname:" << this->pathname << ", name:" << this->name << "}";
}

Multimedia::~Multimedia() {
    cout << "Multimedia object " << name << " destroyed" << endl;

}

