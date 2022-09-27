//
// Created by ivanivan on 9/27/22.
//

#ifndef INF224_PHOTO_H
#define INF224_PHOTO_H

#include <utility>

#include "BaseClass.h"

using namespace std;

class Photo : public BaseClass {
private:
    float latitude{};
    float longitude{};
public:
    Photo(string name, string pathname, float latitude, float longitude);
};


Photo::Photo(string name, string pathname, float latitude, float longitude) : BaseClass(move(name), move(pathname)) {
    this->latitude = latitude;
    this->longitude = latitude;
}


#endif //INF224_PHOTO_H
