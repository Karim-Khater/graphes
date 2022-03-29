#ifndef __EXPR__
#define __EXPR__ 

#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct s_noeud { 
	union {
		 char op;
		 float val;
		  } etiq;
	 struct s_noeud *fg, *fd; 
} noeud, *expr; 


expr exprnouv();
expr enrac(char x, expr g, expr d);
expr creerfeuille(float x);
expr agauche(expr e);
expr adroit(expr e);
bool est_vide(expr e);
bool est_feuille(expr e);
bool est_interne(expr e);
char racine_interne(expr e);
float racine_feuille(expr e);
void affiche(expr e);

#endif