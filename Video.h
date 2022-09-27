//
// Created by ivanivan on 9/27/22.
//

#ifndef INF224_VIDEO_H
#define INF224_VIDEO_H

#include <string>
#include <cstring>
#include <iostream>
#include "BaseClass.h"

using namespace std;

class Video : BaseClass {
private:
    unsigned int duration{};
public:
    Video(string name, string pathname, unsigned int duration) : BaseClass(move(name), move(pathname)) {
        this->duration = duration;
    };

    void print(ostream &output) const override {
        output << "Video{pathname: " << this->getPathname() << ", name:" << this->getName() << ", latitude:"
               << this->duration << "}" << endl;
    };

    void display() const override {
        char command[100] = "mpv ";
        strcat(command, (this->getPathname() + this->getName()).data());
        strcat(command, " &");
        cout << command << endl;
        system(command);
    };
};


#endif //INF224_VIDEO_H
