//
// Created by ivanivan on 9/27/22.
//

#ifndef INF224_VIDEO_H
#define INF224_VIDEO_H

#include <string>
#include "BaseClass.h"

using namespace std;

class Video : BaseClass {
private:
    unsigned int duration{};
public:
    Video(string name, string pathname, unsigned int duration);
};

Video::Video(string name, string pathname, unsigned int duration) : BaseClass(move(name), move(pathname)){
    duration = duration;
}

#endif //INF224_VIDEO_H
