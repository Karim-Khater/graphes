#include "arbrebin.h"


abin arbrevide()
{
        return NULL;
}

//Pré(enrac(x,a1,a2)) ≡ x≠ω et (non vide(a1) ⊃ max(a1)≤x) et (non vide(a2) ⊃ x<max(a2))

abin enraciner(int arb ,abin fg ,abin fd)
{
        abin nouv = malloc(sizeof(noeud));
        nouv->r = arb ;
        nouv->fg = fg ;
        nouv->fd = fd ;
        return nouv ;
}
abin sous_arbre_gauche(abin arb)
{
        return arb->fg;
}
abin sous_arbre_droit(abin arb)
{
        return arb->fd;
}

abin racine(abin arb)
{
        return arb ;
}

int vide(abin arb)
{
        return arb == NULL;
}

int nubnoeuds(abin arb)
{
        if( !arb->fg ||  !arb->fd )
                return 0 ;
        else
        {
                return 1 + nubnoeuds(arb->fg) + nubnoeuds(arb->fd) ;
        }
}
int nubfeuilles(abin arb)
{
        if( !arb->fg && !arb->fd)
                return 1 ;
        else
                return nubfeuilles(arb->fg) + nubfeuilles(arb->fd);
}
int hauteur(abin arb)
{
        if(!arb)
                return 0;
        else{
                return 1 + hauteur(arb->fd) + hauteur(arb->fg);
        }
}
int chemininterne(abin arb)
{
        return 0 ;
}
int cheminexterne(abin arb)
{
       if(!arb)
        return 0 ;
        else{
              return 1+hauteur(arb->fd)+hauteur(arb->fg);  
        }
}
int exist(abin arb);



