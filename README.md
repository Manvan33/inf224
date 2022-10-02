# INF224 - TP C++

## Séance 1 : Étapes 1-5

### Getters

Prenons en exemple un getter de Multimedia:

```c++
const string &Multimedia::getPathname() const {
    return pathname;
}
```

L'utilisation du premier `const` couplé au `&` permet de renvoyer une référence vers la string contenant pathname, nous
évitant une copie superflue.

Le dernier `const` signifie que la méthode ne modifie pas les données de l'objet.

### Étape 4 : Méthode `play()` et polymorphisme

> Cette méthode pourrait être implémentée uniquement dans la classe de base, et faire appel à la commande
> système `xdg-open` qui trouve automatiquement un programme sachant ouvrir le fichier passé en argument. Mais le but de
> l'exercice étant de s'exercer au polymorphisme, nous allons utiliser une commande différente pour chaque type d'objet.

La fonction `play` n'a donc pas d'implémentation au niveau de la classe de base : c'est une méthode **abstraite**
déclarée comme ceci :

```c++
virtual void play() const = 0;
```

On ne peut donc plus instancier d'objet Multimedia car il contient une méthode non implémentée. Les sous-classes doivent
forcément implémenter `play()` pour être instanciables. Le mot-clé `override` signale la redéfinition de méthode.

```c++
void play() const override {...}
```

L'étape 4 est terminée au
commit [e3cea827ef74419845d92af1b35b001802ba3072](https://github.com/Manvan33/inf224/tree/e3cea827ef74419845d92af1b35b001802ba3072)
.

### Étape 5 : Traitement uniforme.

> On veut maintenant pouvoir traiter de manière uniforme une liste comprenant à la fois des photos et des vidéos sans
> avoir à se préoccuper de leur type.
> Pour ce faire créer dans main.cpp un tableau dont les éléments sont tantôt une photo tantôt une vidéo. Ecrire ensuite
> une boucle permettant d'afficher les attributs de tous les élements du tableau ou de les "jouer". Cette boucle doit
> traiter tous les objets dérivant de la classe de base de la même manière.

```c++
Multimedia ** tableau = new Multimedia * [2];
unsigned int count = 0;
tableau[count++] = new Photo("image.gif", "./", 1.0, 2.0);
tableau[count++] = new Video("video.webm", "./", 1);
for (unsigned int i =0; i < count; i++) {
    tableau[i]->print(cout);
    tableau[i]->play();
}
```

**Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?**

Le polymorphisme.

**Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?**

Initialiser le tableau avec des élements Multimedia, cet élément doit donc avoir un constructeur par défaut (sans
paramètres).

**Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ?
Pourquoi ? Comparer à Java.**

Les éléments du tableau sont des objets Photos et Videos, le tableau contient des pointeurs vers ces objets.  
 