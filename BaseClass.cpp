//
// Created by ivanivan on 9/27/22.
//

#include <cstring>
#include <iostream>
#include "BaseClass.h"

using namespace std;

BaseClass::BaseClass() = default;

BaseClass::BaseClass(string name, string pathname) {
    setName(name);
    setPathname(pathname);
}

void BaseClass::setName(string &new_name) {
    BaseClass::name = new_name;
}


void BaseClass::setPathname(string &new_pathname) {
    BaseClass::pathname = new_pathname;
}


const string &BaseClass::getPathname() const {
    return pathname;
}

const string &BaseClass::getName() const {
    return name;
}

void BaseClass::play() const {
    char command[100] = "xdg-open ";
    strcat(command, (this->pathname+this->name).data());
    strcat(command, " &");
    cout << command << endl;
    system(command);
}

void BaseClass::print(ostream & output) const {
    output << "BaseClass{pathname: " << this->pathname << ", name:" << this->name << "}";
}

