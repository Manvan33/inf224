//
// Created by ivanivan on 10/11/22.
//

#ifndef INF224_FILM_H
#define INF224_FILM_H

#include "Video.h"

using namespace std;

class Film : Video {
private:
    unsigned int chaptersCount{};
    unsigned int *chapters;
public:
    ~Film() {
        delete[] chapters;
    }

    //default constructor
    Film() : Video() {
        chaptersCount = 0;
        chapters = nullptr;
    }

    Film(const string &name, const string &pathname, unsigned int duration) : Video(name, pathname, duration) {
        this->chaptersCount = 0;
        this->chapters = nullptr;
    }

    Film(const string &name, const string &pathname, unsigned int duration, const unsigned int *chapters,
         unsigned int nbChapters) : Video(name, pathname, duration) {
        this->chaptersCount = nbChapters;
        this->chapters = new unsigned int[chaptersCount];
        for (unsigned int i = 0; i < nbChapters; i++) {
            this->chapters[i] = chapters[i];
        }
    }

    void setChapters(const unsigned int *chaptersList, unsigned int nbChapters) {
        this->chaptersCount = nbChapters;
        delete[] chapters;
        this->chapters = new unsigned int[chaptersCount];
        for (unsigned int i = 0; i < nbChapters; i++) {
            this->chapters[i] = chaptersList[i];
        }
    }

    void print(ostream &output) const override {
        output << "Film{pathname: " << getPathname() << ", name: " << getName() << ", duration: " << getDuration()
               << ", " << chaptersCount << " chapters: (";
        for (unsigned int i = 0; i < chaptersCount; i++) {
            output << chapters[i];
            if (i < chaptersCount - 1) {
                output << ",";
            }
        }
        output << ")}" << endl;
    }

    unsigned int getChaptersCount() const {
        return chaptersCount;
    }

    const unsigned int *getChapters() const {
        return chapters;
    }

    // Opérateur d'affectation permettant la copie profonde
    Film &operator=(const Film &from) {
        if (this != &from) {
            this->setName(from.getName());
            this->setPathname(from.getPathname());
            this->setDuration(from.getDuration());
            this->setChapters(from.getChapters(), from.getChaptersCount());
        }
        return *this;
    }
};

#endif //INF224_FILM_H
