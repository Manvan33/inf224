//
// Created by ivanivan on 9/27/22.
//

#ifndef INF224_PHOTO_H
#define INF224_PHOTO_H

#include "BaseClass.h"

using namespace std;

class Photo : public BaseClass {
private:
    float latitude{};
    float longitude{};
public:
    Photo(string name, string pathname, float latitude, float longitude);

    float getLatitude() const;

    void setLatitude(float latitude);

    float getLongitude() const;

    void setLongitude(float longitude);
};


Photo::Photo(string name, string pathname, float latitude, float longitude) : BaseClass(move(name), move(pathname)) {
    this->latitude = latitude;
    this->longitude = latitude;
}

float Photo::getLatitude() const {
    return latitude;
}

void Photo::setLatitude(float latitude) {
    Photo::latitude = latitude;
}

float Photo::getLongitude() const {
    return longitude;
}

void Photo::setLongitude(float longitude) {
    Photo::longitude = longitude;
}


#endif //INF224_PHOTO_H
