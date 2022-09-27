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
    Photo(string name, string pathname, float latitude, float longitude) : BaseClass(move(name), move(pathname)) {
        this->latitude = latitude;
        this->longitude = latitude;
    };

    float getLatitude() const {
        return latitude;
    };

    void setLatitude(float latitude) {
        this->latitude = latitude;
    }

    float getLongitude() const {
        return longitude;
    }

    void setLongitude(float longitude) {
        this->longitude = longitude;
    }

    void display() const override {
        BaseClass::display();
    }

    void print(ostream & output) const override {
        output << "Photo{pathname: " << this->getPathname() << ", name:" << this->getName() << ", latitude:"
               << this->latitude
               << ", longitude: " << this->longitude << "}" << endl;
    };

};


#endif //INF224_PHOTO_H
