/******************************************/
/*
// grapheurbain.c
*/

#include "grapheurbain.h"

// operations internes
grapheurbain rechCarrefour(grapheurbain g, unsigned int icar)
{
	// TODO
	grapheurbain tmp=g;
	int bicf=0;
	while(tmp)
	{
		if(tmp->c.icf==icar)
		{
			bicf=1;
		
		break;
		}
		else{
			tmp=tmp->suiv;
		}
	}
	if(bicf==1)
	{
		return tmp;
	}
	else{
		return NULL;
	}
}

ListeSom rechArc(ListeSom ls, unsigned int icar)
{
	// TODO
	ListeSom tmp=ls;
	int bcar=0;
	while(tmp)
	{
		if(tmp->icf==icar)
		{
			bcar=1;
			break;
		}else{
			tmp=tmp->suc;
		}

	}
	if(bcar==1)
	{
		return tmp;
	}
	else{
		return NULL;
	}
	
}

ListeSom rechArcVal(ListeSom ls, unsigned int irue)
{
	// TODO
	ListeSom tmp=ls;
	int brue=0;
	while(tmp)
	{
		if(tmp->irue==irue)
		{
			brue=1;
			break;
		}else{
			tmp=tmp->suc;
		}

	}
	if(brue==1)
	{
		return tmp;
	}
	else{
		return NULL;
	}
	
}

ListeSom supArc(ListeSom ls, unsigned int icar)
{
	// TODO
	ListeSom tmp=ls;
	ListeSom tmp2=ls;
	while(tmp)
	{
		if(tmp->suc->icf==icar)
		{
			tmp2=tmp->suc;
			tmp->suc=tmp->suc->suc;
			free(tmp2);
			break;
		}
		else{
			tmp=tmp->suc;
		}
	}
	return ls;
}

ListeSom adjArc(ListeSom ls, unsigned int icar, unsigned int irue)
{
	// TODO
	ListeSom tmp=ls;
	while(tmp)
	{
		if(tmp->icf==icar )
		{
			tmp->irue=irue;
			break;
		}
		else{
			tmp=tmp->suc;
		}
	}
	return tmp;
}

// creation et destruction
grapheurbain grapheurbainNouv()
{
	
	grapheurbain g =malloc(sizeof(Strsom));
	g->c.icf=0;
	g->c.lsucc=NULL;
	g->c.lpred=NULL;
	
	return g;
	
	
}

void grapheurbainFree(grapheurbain g)
{
	grapheurbain gtmp = g;
	grapheurbain gtmp2 = g;
	while(g){
		gtmp = g ;
		while(gtmp->c.lsucc){
			gtmp2 = gtmp ;
			gtmp->c.lsucc = gtmp->c.lsucc->suc;
			free(gtmp2->c.lsucc);
		}
		gtmp = g ;
		while(gtmp->c.lpred){
			gtmp2 = gtmp ;
			gtmp->c.lpred = gtmp->c.lpred->suc;
			free(gtmp2->c.lpred);
		}
		gtmp = g;
		g = g->suiv ;
		free(gtmp);
	}

}

// operations usuelles sur les graphes
void addCarrefour(grapheurbain *g, unsigned int icar)
{
	grapheurbain test = *g ;
	while(test){
		if(test->c.icf == icar) //il exist ce carrefour
			return;
		test = test->suiv ;
	}
	grapheurbain gtmp = malloc(sizeof(Strsom));
	gtmp->c.icf = icar ;
	gtmp->suiv = *g ;
	g = &gtmp ;
	//printf("%d\n",(*g)->c.icf);

}

void supCarrefour(grapheurbain *g, unsigned int icar)
{
	grapheurbain tmp  = *g ;
	grapheurbain tmp2 ;
	if(*g == NULL)
		return;
	else{
		while(tmp){
			if(tmp->c.icf == icar){
				while(tmp->c.lsucc){
					tmp2 = tmp ;
					tmp->c.lsucc = tmp->c.lsucc->suc ;
					free(tmp2->c.lsucc);
				}
				while(tmp->c.lpred){
					tmp2 = tmp ;
					tmp->c.lpred = tmp->c.lpred->suc ;
					free(tmp2->c.lpred);
				}
				return ;
			}
			else
				tmp = tmp->suiv;
		}
	}
}
// ico et ice peuvent n'existe pas
//precondition  irue n'appartien pas a lsucc de ico ou lpred de ice
void addRue(grapheurbain *g, unsigned int ico, unsigned int ice, unsigned int irue)
{
	grapheurbain tmp=*g;

		
		ListeSom l = malloc(sizeof(Strarc)) ;
		l->irue = irue ;
		l->suc = tmp->c.lsucc ;
		tmp->c.lsucc  = l ;
		//predecesseurs
		ListeSom ll = malloc(sizeof(Strarc));
		ll->irue = irue ;
		tmp = *g ;
		
		ll->suc = tmp->c.lpred ;
		tmp->c.lpred = ll ;
		//printf("%d\n",tmp->c.lpred->irue );
	

	

}

void addRueDoubleSens(grapheurbain *g, unsigned int ico, unsigned int ice, unsigned int irue)
{
	addRue(g,ico,ice ,irue);
	addRue(g,ice ,ico ,irue);
}

void supRue(grapheurbain *g, unsigned int ico, unsigned int ice)
{
		grapheurbain tmp  = *g ;
	grapheurbain tmp2 ;
	if(*g == NULL)
		return;
	else{
		while(tmp){
			if(tmp->c.icf == ico){
				while(tmp->c.lsucc){
					tmp2 = tmp ;
					tmp->c.lsucc = tmp->c.lsucc->suc ;
					free(tmp2->c.lsucc);
				}
			if(tmp->c.icf==ice){	
				while(tmp->c.lpred){
					tmp2 = tmp ;
					tmp->c.lpred = tmp->c.lpred->suc ;
					free(tmp2->c.lpred);
				}
				}
			}
			else
				tmp = tmp->suiv;
		}
	}

	
}

bool existeArc(grapheurbain g, unsigned int ico, unsigned int ice)
{
	
	unsigned int rue1,rue2;
	int bres=0;
	
	grapheurbain tmp = g ;
	while(tmp)
	{
		
		if(tmp->c.lsucc->icf==ico)
			rue1=tmp->c.lsucc->irue;

		if(tmp->c.lpred->icf==ice)
			rue2=tmp->c.lpred->irue;

		tmp=tmp->suiv;
		
	}
	if(rue1==rue2)
		bres=1;

	return bres;
}

bool existeCarrefour(grapheurbain g, unsigned int icar)
{
	grapheurbain tmp  = g ;

	bool bres=0;
	while(tmp){
			if(tmp->c.icf == icar){
				if(tmp->c.lsucc!=NULL){
					if(tmp->c.lpred!=NULL)
					{
						bres=1;
					}
					
				}
				
			}
			else
				tmp = tmp->suiv;
		}
	// TODO
	return bres;
}

// operations sur les liste de succ et pred
// les carrefours associes a une rue
listeui carrefoursDeRue(grapheurbain g, unsigned int irue)
{
	// TODO
	unsigned int car;
	listeui li=nouvlui();
	grapheurbain tmp=g;
	while(tmp)
	{
		if(tmp->c.lsucc->irue==irue){
			car=tmp->c.lsucc->icf;
			li=adjtetelui(li,car);
		}

		tmp=tmp->suiv;
	}

	return li;
}

// les rues incidentes en un carrefour
listeui ruesDeCarrefour(grapheurbain g, unsigned int icar)
{
	// TODO
	unsigned int rue;
	listeui li=nouvlui();
	grapheurbain tmp=g;
	while(tmp)
	{
		if(tmp->c.lsucc->icf==icar)
		{
			rue=tmp->c.lsucc->irue;
			li=adjtetelui(li,rue);
		}
		tmp=tmp->suiv;
	}
	return li;
}

listeui ruesCroisement(grapheurbain g, unsigned int irue)
{
	// TODO
	unsigned int rue;
	listeui li=nouvlui();
	grapheurbain tmp=g;
	while(tmp!=NULL)
	{
		if(tmp->c.lsucc->irue==irue)
		{
			rue=tmp->c.lsucc->suc->irue;
			li=adjtetelui(li,rue);


		}
		tmp=tmp->suiv;

	}
	return li;
}
