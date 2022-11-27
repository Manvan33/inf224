//
// Created by ivanivan on 9/27/22.
//

#ifndef INF224_VIDEO_H
#define INF224_VIDEO_H

#include <string>
#include <cstring>
#include <iostream>
#include "Multimedia.h"

using namespace std;

class Video : public Multimedia {
private:
    unsigned int duration{};
public:
    Video() : Multimedia() {
        duration = 0;
    }
    Video(string name, string pathname, unsigned int duration) : Multimedia(move(name), move(pathname)) {
        this->duration = duration;
    };

    unsigned int getDuration() const {
        return duration;
    }

    void setDuration(unsigned int new_duration) {
        Video::duration = new_duration;
    }


    void print(ostream &output) const override {
        output << "Video{pathname:" << this->getPathname() << ", name:" << this->getName() << ", duration:"
               << this->getDuration() << "}";
    };


    void play() const override {
        string command = "vlc ";
        command += this->getPathname() + this->getName() + " &";
        cout << "Launching system command: " << command << endl;
        system(command.data());
    }

};


#endif //INF224_VIDEO_H
