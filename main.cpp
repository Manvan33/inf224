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
//    auto *empty = new Multimedia();
//    auto *complex = new Multimedia("hello", "/tmp/hello");
//    std::cout << "Empty class name: " << empty->getName() << std::endl;
//    std::cout << "Complex class pathname " << complex->getPathname() << std::endl;
    // Etape 4
    Photo *photo = new Photo("image.gif", "./", 23.2, 13.1);
    std::cout << "Photo pathname: " << photo->getPathname() << std::endl;
    photo->print(cout);
    Video *video = new Video("video.webm", "./", 14);
    video->print(cout);
    photo->play();
    video->play();
    // Etape 5
    Multimedia ** tableau = new Multimedia * [2];
    unsigned int count = 0;
    tableau[count++] = new Photo("image.gif", "./", 1.0, 2.0);
    tableau[count++] = new Video("video.webm", "./", 1);
    for (unsigned int i =0; i < count; i++) {
        tableau[i]->print(cout);
        tableau[i]->play();
    }

    return 0;
}
