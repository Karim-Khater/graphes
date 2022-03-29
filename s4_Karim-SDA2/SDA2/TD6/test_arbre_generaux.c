#include "arbre_generaux.h"

int main()
{
	arbre arb=arbrevide();
	arbre frere1=arbrevide();
	arbre frere2=arbrevide();
	arbre fils1=arbrevide();
	arbre fils2=arbrevide();
	arbre fils3=arbrevide();
	arbre empty=arbrevide();
	printf("vide? :%d\n",est_vide(fils2) );
	fils3=nouvnoeud(5,empty,empty);
	fils2=nouvnoeud(2,fils3,empty);
	frere2=nouvnoeud(3,empty,empty);
	frere1=nouvnoeud(6,frere2,empty);
	fils1= nouvnoeud(1,frere1,fils2);
	arb = nouvnoeud(4,empty,fils1);
	printf("vide? :%d\n",est_vide(arb) );
	printf("val :%d\n",arb->val );
	printf("val :%d\n",fils(arb)->val );
	printf("val :%d\n",frere(arb->fils)->val );
	printf("val :%d\n",fils(fils(arb))->val );
	printf("feuille : %d\n",est_feuille(arb->fils->frere) );
	printf("feuille : %d\n",est_feuille(arb->fils) );
	printf("nb_fils :%d\n",nb_fils(arb) );
	printf("exist :%d\n",exist(3,arb)->val );
	printf("hauteur :%d %d\n",hauteur(arb),hauteur(fils2));
	

	affiche(arb);
}

