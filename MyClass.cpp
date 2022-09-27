//
// Created by ivanivan on 9/27/22.
//

#include "MyClass.h"

MyClass::MyClass() {}

MyClass::MyClass(std::string name, std::string pathname) {
    setName(name);
    setPathname(pathname);
}

void MyClass::setName(std::string &name) {
    MyClass::name = name;
}


void MyClass::setPathname(std::string &pathname) {
    MyClass::pathname = pathname;
}


const string &MyClass::getPathname() const {
    return pathname;
}

const string &MyClass::getName() const {
    return name;
}
