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

class Video : public BaseClass {
private:
    unsigned int duration{};
public:
    Video(string name, string pathname, unsigned int duration) : BaseClass(move(name), move(pathname)) {
        this->duration = duration;
    };

    unsigned int getDuration() const {
        return duration;
    }

    void setDuration(unsigned int new_duration) {
        Video::duration = new_duration;
    }


    void print(ostream &output) const override {
        output << "Video{pathname: " << this->getPathname() << ", name:" << this->getName() << ", latitude:"
               << this->duration << "}" << endl;
    };

};


#endif //INF224_VIDEO_H
