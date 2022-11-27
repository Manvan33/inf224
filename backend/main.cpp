#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Groupe.h"
#include "DataMap.h"


using namespace std;

int main(int argc, const char *argv[]) {
//    auto *empty = new Multimedia();
//    auto *complex = new Multimedia("hello", "/tmp/hello");
//    std::cout << "Empty class name: " << empty->getName() << std::endl;
//    std::cout << "Complex class pathname " << complex->getPathname() << std::endl;
    // Etape 4
    cout << endl << "### Étape 4: Photos et vidéos" << endl;
    auto *photo = new Photo("image.gif", "./", 23.2, 13.1);
    std::cout << "Photo pathname: " << photo->getPathname() << std::endl;
    photo->print(cout);
    auto *video = new Video("video.webm", "./", 14);
    video->print(cout);
    // photo->play();
    // video->play();
    // Etape 5
    cout << endl << "### Étape 5: Polymorphisme" << endl;
    auto ** tableau = new Multimedia * [2];
    unsigned int count = 0;
    tableau[count++] = new Photo("image.gif", "./", 1.0, 2.0);
    tableau[count++] = new Video("video.webm", "./", 1);
    for (unsigned int i =0; i < count; i++) {
        tableau[i]->print(cout);
        // tableau[i]->play();
    }
    // Etape 6
    cout << endl << "### Étape 6: Films" << endl;
    Film * film = new Film("video.webm", "./", 1, new unsigned int[2]{1, 2}, 2);
    film->print(cout);
    // Etape 7
    cout << endl << "### Étape 7: Testons la copie profonde." << endl;
    // Test deep copy of Film, deleting the original instance
    Film film2;
    film2 = *film;
    cout << "film2, copie de film1:" << endl;
    film2.print(cout);
    delete film;
    cout << "film1 supprimé, film2 est-il affecté ?" << endl;
    film2.print(cout);
    cout << "film2 n'est pas affecté, la copie profonde a bien fonctionné" << endl;
    // Etape 8
    cout << endl << "### Étape 8: Groupes" << endl;
    cout << "ne fonctionne plus après l'implémentation de l'étape 9 avec les smart pointers" << endl;
    // Groupe * groupe1 = new Groupe("groupe1");
    // groupe1 -> push_back(photo);
    // groupe1 -> push_back(video);
    // groupe1 -> print(cout);
    // Groupe * groupe2 = new Groupe("groupe2");
    // groupe2 -> push_back(&groupe1->back());
    // groupe2 -> print(cout);
    // delete groupe1;
    // cout << "groupe1 supprimé, groupe2 est-il affecté ?" << endl;
    // groupe2->print(cout);
    // cout << "Tout va bien :D" << endl;

    // Etape 9
    cout << endl << "### Étape 9: Smart pointers" << endl;
    auto *groupe1 = new Groupe("groupe1");
    MultimediaPtr smart_photo = make_shared<Photo>("image.gif", "./", 1.0, 2.0);
    groupe1->push_back(smart_photo);
    MultimediaPtr smart_video = make_shared<Video>("video.webm", "./", 1);
    groupe1->push_back(smart_video);
    auto *groupe2 = new Groupe("groupe2");
    groupe2->push_back(smart_photo);
    cout << "Suppression des pointeurs temporaires"<< endl;
    smart_photo.reset();
    smart_video.reset();
    groupe1->print(cout);
    groupe2->print(cout);
    delete groupe1;
    cout << "groupe1 supprimé, groupe2 est-il affecté ?" << endl;
    groupe2->print(cout);
    delete groupe2;
    // Etape 10
    cout << endl << "### Étape 10: Gestion cohérente des données" << endl;
    DataMap datamap = DataMap();
    shared_ptr<Photo> photo_object = datamap.create_photo("image.gif", "./", 1.0, 2.0);
    shared_ptr<Video> vid_object = datamap.create_video("video.webm", "./", 1);
    datamap.print_object(cout, "image.gif");
    GroupePtr groupeptr = datamap.create_group("main_group");
    groupeptr->push_back(photo_object);
    groupeptr->push_back(vid_object);
    datamap.print_group(cout, "main_group");
    cout << endl << "Exiting main" << endl;
    return 0;


}
