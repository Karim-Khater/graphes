#include "arbre_generaux.h"

arbre arbrevide()
{
	return NULL;
}
arbre nouvnoeud(T x, arbre frere, arbre fils)
{
	arbre nouv = malloc(sizeof(noeud));
	nouv->val=x;
	nouv->frere=frere;
	nouv->fils=fils;
	return nouv;
}
arbre fils(arbre a)
{
	return a->fils;
} 
arbre frere(arbre a)
{
	return a->frere;
}
bool est_vide(arbre a)
{
	return (a==NULL);
}
bool est_feuille(arbre a) 
{
	if(a->fils==NULL){
		return 1;
	}else{
		return 0;
	}
}
bool est_fils(T x, arbre a)
{
	
	if(a->fils->val==x){
		return 1;
	}else{
		return 0;
	}

} 			       
unsigned int nb_fils(arbre a)
{
	
	if(a->fils==NULL)
	   return 0;
	else{
		unsigned int b=1;
		arbre arb=a->fils->frere;
		
		while(arb!=NULL)
			{	
				b=b+1;
				arb=arb->frere;
			}
		return b;	
	}
}

unsigned int hauteur(arbre a)
{
	if(!a)
			return 0;
	else if(a->fils==NULL)
			return 1;
	else{	
	return (int)fmax(1. + hauteur(fils(a)),hauteur(frere(a)));
	}
}

arbre exist(T x,arbre a)
{
	
	
	if(a->val==x)
	{
		return a;
	}
	else if(a->fils==NULL && a->frere==NULL){
		return NULL;
	}
	else if(a->fils!=NULL && a->frere==NULL)
	{
		return exist(x,fils(a));
	}
	else if(a->fils==NULL && a->frere!=NULL)
	{
		return exist(x,frere(a));
	}
	else
	{
		if(exist(x,frere(a))==NULL){
			return exist(x,fils(a));
		}

		if(exist(x,fils(a))==NULL){
			return exist(x,frere(a));
		}
		
	}
	return exist(x,a);
	
}
void affi(arbre a, char *decal)
{
	char buffer[3];
	snprintf(buffer,sizeof(buffer),"%s ",decal);
	if(a!=NULL)
	{
		printf("%s|%d\n",decal,a->val );
		affi(a->fils,buffer);
		affi(a->frere,decal);
	}
}
void affiche(arbre a)
{
	affi(a,"");
			
}	