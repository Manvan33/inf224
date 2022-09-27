//
// Created by ivanivan on 9/27/22.
//

#ifndef INF224_PHOTO_H
#define INF224_PHOTO_H

#include "Multimedia.h"

using namespace std;

class Photo : public Multimedia {

    float latitude{};
    float longitude{};

public:
    Photo(string name, string pathname, float latitude, float longitude) : Multimedia(move(name), move(pathname)),
                                                                           latitude(latitude), longitude(longitude) {};

    float getLatitude() const {
        return latitude;
    };

    void setLatitude(float new_latitude) {
        this->latitude = new_latitude;
    }

    float getLongitude() const {
        return longitude;
    }

    void setLongitude(float new_longitude) {
        this->longitude = new_longitude;
    }

    void print(ostream &output) const override {
        output << "Photo{pathname: " << this->getPathname() << ", name:" << this->getName() << ", latitude:"
               << this->latitude
               << ", longitude: " << this->longitude << "}" << endl;
    };

    void play() const override {
        string command = "firefox ";
        command += this->getPathname() + this->getName() + " &";
        cout << "Launching system command: " << command << endl;
        system(command.data());
    }

};

#endif //INF224_PHOTO_H