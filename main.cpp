//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "BaseClass.h"
#include "Photo.h"
#include "Video.h"


using namespace std;

int main(int argc, const char *argv[]) {
    BaseClass *empty = new BaseClass();
    BaseClass *complex = new BaseClass("hello", "/tmp/hello");
    std::cout << "Empty class name: " << empty->getName() << std::endl;
    std::cout << "Complex class pathname " << complex->getPathname() << std::endl;
    Photo *photo = new Photo("bg.png", "/tmp/", 23.2, 13.1);
    std::cout << "Photo pathname: " << photo->getPathname() << std::endl;
    photo->print(cout);
    Video *video = new Video("video.mp4", "/tmp/", 4);
    video->print(cout);
    photo->display();
    video->display();
    return 0;
}
