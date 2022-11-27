//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"


using namespace std;

int main(int argc, const char *argv[]) {
//    auto *empty = new Multimedia();
//    auto *complex = new Multimedia("hello", "/tmp/hello");
//    std::cout << "Empty class name: " << empty->getName() << std::endl;
//    std::cout << "Complex class pathname " << complex->getPathname() << std::endl;
    // Etape 4
    auto *photo = new Photo("image.gif", "./", 23.2, 13.1);
    std::cout << "Photo pathname: " << photo->getPathname() << std::endl;
    photo->print(cout);
    auto *video = new Video("video.webm", "./", 14);
    video->print(cout);
    photo->play();
    video->play();
    // Etape 5
    auto ** tableau = new Multimedia * [2];
    unsigned int count = 0;
    tableau[count++] = new Photo("image.gif", "./", 1.0, 2.0);
    tableau[count++] = new Video("video.webm", "./", 1);
    for (unsigned int i =0; i < count; i++) {
        tableau[i]->print(cout);
        tableau[i]->play();
    }
    Film * film = new Film("video.webm", "./", 1, new unsigned int[2]{1, 2}, 2);
    film->print(cout);

    cout << "Testons la copie profonde." << endl;
    // Test deep copy of Film, deleting the original instance
    Film film2;
    film2 = *film;
    cout << "film2, copie de film1:" << endl;
    film2.print(cout);
    delete film;
    cout << "film1 supprimé, film2 est-il affecté ?" << endl;
    film2.print(cout);
    cout << "film2 n'est pas affecté, la copie profonde a bien fonctionné" << endl;

    return 0;
}
