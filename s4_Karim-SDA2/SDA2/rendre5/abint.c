#include "abint.h"

abint nouv()
{
	return NULL;
}
abint enrac(T x,abint g,abint d)
{
	abint a=malloc(sizeof(abint));
	a->etiq=x;
	a->ag=g;
	a->ad=d;
	if(g==NULL&&d==NULL)
		a->h=0;
	else if(g==NULL && d!=NULL)
		a->h=d->h +1;
	else if(g!=NULL && d==NULL)
		a->h=g->h +1;
	else{
		if(g->h>d->h)
			a->h=g->h +1;
		else
			a->h=d->h +1;
	}
	return a;
}
abint racine(abint a)
{
	return a;
}
abint gauche(abint a)
{
	return a->ag;
}
abint droit(abint a)
{
	return a->ad;
}
bool vide(abint a)
{
	return (a==NULL);
}

abint rech(abint a,T x)
{
	if(a==NULL)
		return a;
	
	if(a->etiq==x){

		return a;
	}else{
		if(x<a->etiq)
			return rech(a->ag,x);
		else
			return rech(a->ad,x);
	
	}
	
}

bool est_trie(abint a)
{
	if(a->ag==NULL)
		return true;
	else()
}
int main()
{
	abint a=nouv();
	abint b=nouv();
	abint c=nouv();
	printf("vide? :%d\n",vide(c) );
	c=enrac(0,a,b);
	abint d=enrac(3,NULL,NULL);
	abint e=enrac(2,c,d);
	printf("hauteur :%d\n",c->h );
	printf("hauteur :%d\n",e->h );
	printf("vide? :%d\n",vide(c) );
	printf("%d \n",rech(e,3)->etiq);
	return 0;
}