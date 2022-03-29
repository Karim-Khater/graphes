#ifndef __ARBRE_GENERAUX__
#define __ARBRE_GENERAUX__ 

#define T int
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct s_noeud { 
	T val; 
	struct s_noeud *fils,*frere;
	 } noeud, *arbre; 

arbre arbrevide();
arbre nouvnoeud(T x, arbre frere, arbre fils); // création
arbre fils(arbre a); // récupérer le premier fils 
arbre frere(arbre a) ; // récupérer le frère 
bool est_vide(arbre a); 
bool est_feuille(arbre a) ; 
bool est_fils(T x, arbre a) ; // teste si x est un des fils 
			      // de a (fils, pas descendant) 
unsigned int nb_fils(arbre a);   // nombre de fils de a,  
				 //dans l’exemple « 4 » a trois fils 
unsigned int hauteur(arbre a);
arbre exist(T x,arbre a);

void affiche(arbre a);


#endif