//
// Created by ivanivan on 9/27/22.
//

#include <cstring>
#include <iostream>
#include "BaseClass.h"

BaseClass::BaseClass() {}

BaseClass::BaseClass(std::string name, std::string pathname) {
    setName(name);
    setPathname(pathname);
}

void BaseClass::setName(std::string &name) {
    BaseClass::name = name;
}


void BaseClass::setPathname(std::string &pathname) {
    BaseClass::pathname = pathname;
}


const string &BaseClass::getPathname() const {
    return pathname;
}

const string &BaseClass::getName() const {
    return name;
}

void BaseClass::display() const {
    char command[100] = "xdg-open ";
    strcat(command, (this->pathname+this->name).data());
    strcat(command, " &");
    cout << command << endl;
    system(command);
}

void BaseClass::print(std::ostream & output) const {
    output << "BaseClass{pathname: " << this->pathname << ", name:" << this->name << "}";
}

