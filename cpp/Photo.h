//
// Created by ivanivan on 9/27/22.
//

#ifndef INF224_PHOTO_H
#define INF224_PHOTO_H

#include <iostream>
#include "Multimedia.h"

using namespace std;

/// \brief A class that represents a photo.
/// \details A photo is a multimedia object that has latitude and a longitude. It can open the related image file
///  from its pathname + name attributes
/// \author Ivan Ivanov
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
        output << "Photo{pathname:" << this->getPathname() << ", name:" << this->getName() << ", latitude:"
               << this->latitude << ", longitude: " << this->longitude << "}";
    };

    void play() const override {
        string command = "xdg-open ";
        command += this->getPathname() + this->getName() + " &";
        cout << "Launching system command: " << command << endl;
        system(command.data());
    }

};

#endif //INF224_PHOTO_H