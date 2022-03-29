#include <stdio.h>
#include <stdlib.h>



typedef struct s_noeud {
        int r;
        struct s_noeud *fg, *fd;
} noeud, *abin;

abin arbrevide();
abin enraciner(int a, abin fg ,abin fd);
abin sous_arbre_gauche(abin a);
abin sous_arbre_droit(abin a);
abin racine(abin a);
int vide(abin a);

int nubnoeuds(abin a);
int nubfeuilles(abin a);
int hauteur(abin a);
int chemininterne(abin a);
int cheminexterne(abin a);
int exist(abin a);
