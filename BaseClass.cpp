//
// Created by ivanivan on 9/27/22.
//

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
