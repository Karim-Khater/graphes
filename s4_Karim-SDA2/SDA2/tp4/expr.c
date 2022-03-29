#include "expr.h"


expr exprnouv()
{
	return NULL;	
}
expr enrac(char x, expr g, expr d)
{
	expr arb=malloc(sizeof(noeud));
	arb->etiq.op=x;
	arb->fg=g;
	arb->fd=d;
	return arb;
}
expr creerfeuille(float x)
{
	expr arb=malloc(sizeof(noeud));
	arb->etiq.val=x;
	arb->fg=NULL;
	arb->fd=NULL;
	return arb;
}
expr agauche(expr e)
{
	return e->fg;
}
expr adroit(expr e)
{
	return e->fd;
}
bool est_vide(expr e)
{
	return (e==NULL);
}
bool est_feuille(expr e)
{
	return (e->fg==NULL && e->fd==NULL);
}
bool est_interne(expr e)
{
	return(e->fg!=NULL || e->fd!=NULL);
}
char racine_interne(expr e)
{
	if(est_interne(e))
		return e->etiq.op;
	else{
		printf("est une feuille\n");
		return '\0';
	}
}
float racine_feuille(expr e)
{
	if(est_feuille(e))
		return e->etiq.val;
	else{
		printf("est une racine interne\n");
		exit(1);
	}
}
void affiche(expr e)
{
	static int count=6;

	if(e==NULL)
		exit(1);
	else if(est_feuille(e))
	{
		printf("%f\n",racine_feuille(e) );
	}
	else
	{
		if(count==1)
		{
			printf("(");
		} 
		if( count ==3)
			{
			printf(")");
			}
		
		if(adroit(e)!=NULL)
		{
			
	  	printf("%.2f ",racine_feuille(adroit(e)) );
	  	++count;
	  	count%=3;
	  	
	  	printf("%c ",racine_interne(e) );
		affiche(agauche(e));
		}else{
			
			printf("%c",racine_interne(e) );
			printf("%.2f",racine_feuille(agauche(e)) );
			printf(")");

		}
		

	}
	  



}
int main()
{
	expr arb=exprnouv();
	expr arbp=exprnouv();
	expr arb5=exprnouv();
	expr arb1=exprnouv();
	expr arbm=exprnouv();
	expr arbe=exprnouv();
	expr arb2=exprnouv();
	arb2=creerfeuille(2.0);
	arb1=creerfeuille(1.0);
	arb5=creerfeuille(5.0);
	arbm=enrac('-',arb2,arbe);
	arbp=enrac('+',arbm,arb1);
	arb=enrac('*',arbp,arb5);
	affiche(arb);
	/*printf("interne :%c\n",racine_interne(arb) );
	printf("interne :%c\n",racine_interne(arbp) );
	printf("interne :%c\n",racine_interne(arbm) );
	printf("feuille :%f\n",racine_feuille(arb5) );
	printf("feuille :%f\n",racine_feuille(arb1) );
	printf("feuille :%f\n",racine_feuille(arb2) );
	printf("interne? :%d\n",est_interne(arb) );
	printf("interne? :%d\n",est_interne(arb1) );
	printf("feuille? :%d\n",est_feuille(arb) );
	printf("feuille? :%d\n",est_feuille(arb5) );*/
}