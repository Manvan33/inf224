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

> Le groupe ne doit pas détruire les objets quand il est détruit, car un objet peut appartenir à plusieurs groupes (on 
> verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de 
> pointeurs d'objets. Pourquoi ? Comparer à Java. 

La liste doit être une liste de pointeurs, car les objets du groupe auront des types différents : Photo, Video, Film,
(classes filles de la classe Multimedia). Nous ne pouvons donc pas les stocker dans une liste de type `list<Multimedia>`.
En Java, même pour une liste dont tous les éléments ont le même type, on stocke des pointeurs vers ces objets.

### 9e étape. Gestion automatique de la mémoire

On crée un type `MultimediaPtr` défini comme un smart pointer vers un objet de type `Multimedia`. On change aussi la 
définition de la classe Groupe, qui hérite maintenant de `list<MultimediaPtr>`.

```c++
typedef std::shared_ptr<Multimedia> MultimediaPtr;

class Groupe : public list<MultimediaPtr> {...}
```

On teste la destruction automatique des objets dans [main.cpp](main.cpp). On instancie un groupe contenant smart_photo 
et `smart_video`, et un second groupe contenant uniquement `smart_photo`. On détruit le premier groupe, le destructeur de 
`smart_video` est bien appelé : "Multimedia object video.webm destroyed". `smart_photo` est toujours utilisé par le second 
groupe, il n'est pas détruit. On détruit le second groupe, `smart_photo` est détruit : "Multimedia object image.gif 
destroyed".

### Étape 10 : Gestion cohérente des données

On écrit la classe DataMap qui utilise deux maps : une map de type `std::map<string, MultimediaPtr>` pour stocker les 
objets et une map de type `std::map<string, GroupePtr>` pour stocker les groupes. On utilise des smart pointers comme 
dans la question précédente.

> Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on 
> l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il
> n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets 
> puisse en créer de nouveaux ?

On peut interdire la création d'objets directement avec new en rendant le constructeur de la classe Multimedia privé, et 
définir la classe DataMap comme amie de la classe Multimedia.

```c++
class Multimedia {
    friend class DataMap;
    ...
}
```
# TP INF224 - Frontend - Java Swing

## Étape 1 : Fenêtre principale et quelques interacteurs

Nous avons créé la fenêtre principale avec 1 champ d'édition de texte positionné au dessus de 3 boutons : "oui", "non"
et "Quitter".

Les deux premiers boutons ajoutent une ligne de texte dans le champ, le troisième bouton ferme la fenêtre.

> Lancez votre programme, cliquez plusieurs fois sur les deux premiers bouton, retaillez la fenêtre. Que constate-t'on ?

On constate que le texte dépasse de la fenêtre, nous l'insérons au sein d'un composant `JScrollPane` qui rajoute un
ascenseur vertical et horizontal lorsque c'est nécessaire.

## Étape 2 : Menus, barre d'outils et actions

Rien de particulier dans cette étape

## Étape 3 : Interface de Télécommande

Le résultat est visible en exécutant `make run`
