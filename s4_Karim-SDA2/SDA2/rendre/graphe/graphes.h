#ifndef __GRAPHES__
#define __GRAPHES__ 

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int S;


typedef struct strarc {
	S v;
	struct strarc *suc;
			} Strarc, *ListeSom; 

typedef struct {
	S v;
	ListeSom ls;
		} Couple; 

typedef struct strsom {
	Couple c;
	struct strsom *suiv;
			} Strsom, *Graphe;


Graphe grnouv();
Graphe adjs(Graphe g, S x);
Graphe adja(Graphe g, S x,S y) ;

Graphe sups(Graphe g,S x);
Graphe supa(Graphe g,S x, S y);

int exs(Graphe g, S x) ;
int exa(Graphe g, S x, S y) ;


#endif