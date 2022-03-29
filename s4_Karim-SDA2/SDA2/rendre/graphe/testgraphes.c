#include "graphes.h"
int main() {
        Graphe g = grnouv();
        g = adjs(g ,1) ;
        g =adjs(g,50);
        g = adjs(g ,22) ;
        g = adjs(g,3); 
         printf("Existence de Sommet : %d\n",exs(g,1));
         printf("Existence de Sommet : %d\n",exs(g,22));
        g = adja(g ,1,22) ;
        g = adja(g,22,1);
        printf("Existence de Arc : %d\n",exa(g,1,22));
        printf("Existence de Arc : %d\n",exa(g,1,3));
        g= sups(g,3) ;
        printf("Existence de Arc : %d\n",exa(g,1,3));
         printf("Existence de Arc : %d\n",exa(g,1,22));
        g = sups(g,22);
        printf("Existence de Arc : %d\n",exa(g,1,22));
        printf("Existence de Sommet : %d\n",exs(g,22));
        g= adjs(g,5);
        g = adja(g ,1,5) ;
        g = adja(g,5,1);
        g= supa(g,5,1);
        printf("Existence de Sommet : %d\n",exs(g,5));
       printf("Existence de Arc : %d\n",exa(g,1,5));
       printf("Existence de Arc : %d\n",exa(g,5,1));
        
        return 0;
}