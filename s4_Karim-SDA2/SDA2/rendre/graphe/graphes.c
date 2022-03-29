#include "graphes.h"

Graphe grnouv()
{
	Graphe g=NULL;
	return g;
}

Graphe adjs(Graphe g, S x)
{
	Graphe gr=malloc(sizeof(Strsom));
	if(!gr)
		exit(1);

	gr->c.v=x;
	gr->c.ls=NULL;
	gr->suiv=g;

	return gr;
}
Graphe adja(Graphe g, S x ,S y)
{
	Graphe gr =g;
	ListeSom arc=malloc(sizeof(Strarc));
	if(!arc)
		exit(1);
	while(gr->c.v != x){
		gr=gr->suiv;
	}
	arc->v=y;
	arc->suc=gr->c.ls;
	gr->c.ls=arc;

	return g;
}

Graphe sups(Graphe g, S x)
{
	Graphe gr=g;
	if(gr->c.v==x)
		return gr->suiv;
	
	else{
		return adjs(sups(gr->suiv,x),gr->c.v);
	
	}

	

}

Graphe supa(Graphe g, S x, S y)
{
	Graphe gr =g;
	if(g==grnouv())
		return grnouv();

	else if(gr->c.v==x && gr->c.ls->v==y)
		return gr->suiv;
	else {
		return adja(supa(gr->suiv,x,y),gr->c.v,gr->c.ls->v);
	}
}


int exs(Graphe g, S x){
        int b=0;
        while(g){
                if(g->c.v == x )
                {
                        b= 1 ;
                }
                g = g->suiv ;
        }
        return b ;
}
int exa(Graphe g, S x, S y){
       
        int b=0;
        while(g){
        	if(g->c.v==x && g->c.ls->v==y)
        	{
        		b=1;
        	}
        	g=g->suiv;
        }
        return b;

}



