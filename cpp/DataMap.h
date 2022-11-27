#ifndef INF224_DATAMAP_H
#define INF224_DATAMAP_H

#include <string>
#include <map>
#include "Groupe.h"
#include "Film.h"
#include "Photo.h"
#include "Video.h"

using namespace std;
typedef std::shared_ptr<Groupe> GroupePtr;

/// \brief DataMap class, a single class to ~~rule them all~~ store all the multimedia objects and groups
/// \author Ivan Ivanov
class DataMap {
private:
    map<string, MultimediaPtr> objects;
    map<string, GroupePtr> groups;
public:
    shared_ptr<Photo> create_photo(string name, string pathname, int latitude, int longitude) {
        shared_ptr<Photo> photo = make_shared<Photo>(name, pathname, latitude, longitude);
        objects[name] = photo;
        return photo;
    }

    shared_ptr<Video> create_video(string name, string pathname, unsigned int duration) {
        shared_ptr<Video> video = make_shared<Video>(name, pathname, duration);
        objects[name] = video;
        return video;
    }

    shared_ptr<Film> create_film(const string &name, const string &pathname, unsigned int duration) {
        shared_ptr<Film> film = make_shared<Film>(name, pathname, duration);
        objects[name] = film;
        return film;
    }

    shared_ptr<Groupe> create_group(string name) {
        shared_ptr<Groupe> group = make_shared<Groupe>(name);
        groups[name] = group;
        return group;
    }

    MultimediaPtr find_object(string name) {
        if (objects.find(name) != objects.end()) {
            return objects[name];
        } else {
            cout << "Object \"" << name << "\" not found" << endl;
            return nullptr;
        }
    }

    GroupePtr find_group(string name) {
        if (groups.find(name) != groups.end()) {
            return groups[name];
        } else {
            cout << "Group \"" << name << "\" not found" << endl;
            return nullptr;
        }
    }

    void print_object(ostream &output, string name) {
        if (find_object(name) != nullptr) find_object(name)->print(output);
        else output << "NOT_FOUND";
    }

    void print_group(ostream &output, string name) {
        if (find_group(name) != nullptr) find_group(name)->print(output);
        else output << "NOT_FOUND";
    }

    void play_object(string name) {
        if (find_object(name) != nullptr) find_object(name)->play();
    }

    void play_group(string name) {
        if (find_group(name) != nullptr) find_group(name)->play();
    }
};


#endif //INF224_DATAMAP_H
