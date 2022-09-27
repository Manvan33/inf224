//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "BaseClass.h"
#include "Photo.h"


using namespace std;

int main(int argc, const char* argv[])
{
    BaseClass * empty = new BaseClass();
    BaseClass * complex = new BaseClass("hello", "/tmp/hello");
    std::cout << "Empty class name: " << empty->getName() << std::endl;
    std::cout << "Complex class pathname: " << complex->getPathname() << std::endl;
    Photo * photo = new Photo("photo.png", "/tmp/photo.png", 23.2, 13.1);
    std::cout << "Photo pathname: " << photo->getPathname() << std::endl;
    return 0;
}
