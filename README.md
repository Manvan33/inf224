# INF224 - TP C++

## Etapes 1-4

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

### Méthode `play()` et polymorphisme

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

L'étape 4 est terminée au commit [e3cea827ef74419845d92af1b35b001802ba3072](https://github.com/Manvan33/inf224/tree/e3cea827ef74419845d92af1b35b001802ba3072).
