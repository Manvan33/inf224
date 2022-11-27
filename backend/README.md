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

## Séance 2 : Étapes 6-10

### Étape 6 : Films et tableaux

> voir le fichier [Film.h](Film.h)

L'étape est terminée au
commit [5758f96bdf5d5e233ed9a411f82a92985873eafa](https://github.com/Manvan33/inf224/tree/5758f96bdf5d5e233ed9a411f82a92985873eafa)

### Étape 7 : Destruction et copie d'objets

> La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est
> le problème et quelles sont les solutions ? Implémentez-en une.

C'est le problème de la copie superficielle (_shallow copy_) : les objets copiés contiendront des pointeurs vers les
mêmes variables d'instance que l'objet d'origine. Or, on ne veut pas que la destruction d'un objet détruise les
variables d'instance d'un autre objet, il faut donc faire une copie profonde (_deep copy_). Pour cela, nous
redéfinissons l'opérateur d'affectation de Film.

```c++
Film &operator=(const Film &from)
```

Nous testons la copie profonde dans [main.cpp](main.cpp), tout fonctionne.

 ### Étape 8 : Créer des groupes 

On crée une classe Groupe qui hérite de la classe `list<Multimedia *>` et on marque cet héritage comme public afin de 
pouvoir utiliser les méthodes de `list` sur un objet de type `Groupe`.

> Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on 
> verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de 
> pointeurs d'objets. Pourquoi ? Comparer à Java. 

La liste doit être une liste de pointeurs car les objets du groupe auront des types différents : Photo, Video, Film,
(classes filles de la classe Multimedia). Nous ne pouvons donc pas les stocker dans une liste de type `list<Multimedia>`.
En Java, même pour une liste dont tous les éléments ont le même type, on stocke des pointeurs vers ces objets.

