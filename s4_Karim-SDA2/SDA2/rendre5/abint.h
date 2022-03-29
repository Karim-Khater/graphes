#ifndef __ABINT__
#define __ABINT__ 
#define T unsigned int

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stdbool.h"
typedef struct s_abint {
        		T etiq;
        	        unsigned int h;
                     	struct s_abint *ag, *ad; 
                     } *abint ;

abint nouv();
abint enrac(T x,abint g,abint d);
abint racine(abint a);
abint gauche(abint a);
abint droit(abint a);
bool vide(abint a);

abint rech(abint a,T x);
bool est_trie(abint a);

#endif