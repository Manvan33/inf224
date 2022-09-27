//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"


using namespace std;

int main(int argc, const char *argv[]) {
    auto *empty = new Multimedia();
    auto *complex = new Multimedia("hello", "/tmp/hello");
    std::cout << "Empty class name: " << empty->getName() << std::endl;
    std::cout << "Complex class pathname " << complex->getPathname() << std::endl;
    auto *photo = new Photo("bg.png", "/tmp/", 23.2, 13.1);
    std::cout << "Photo pathname: " << photo->getPathname() << std::endl;
    photo->print(cout);
    auto *video = new Video("video.mkv", "/tmp/", 4);
    video->print(cout);
    photo->play();
    video->play();
    return 0;
}
