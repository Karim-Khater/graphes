#include "arbrebin.h"
int main(int argc, char const *argv[]) {
        (void) argc ;
        (void) argv ;


        abin arb1 = enraciner(8,NULL ,NULL);
        abin arb2 = enraciner(5,NULL ,NULL) ;
        abin arb3 = enraciner(6,NULL ,NULL) ;
        abin arb4 = enraciner(50,NULL ,NULL) ;
        abin arb5 = enraciner(200,arb3,arb4);
        abin arb6 = enraciner(20,arb1 , arb2) ;
        abin res = enraciner(33 , arb5 , arb6);

        abin tmp = sous_arbre_gauche(arb5) ;
        printf("%d\n",tmp->r );

        printf("%d\n", nubnoeuds(res));
        printf("%d\n",nubfeuilles(res));
        printf("%d\n",hauteur(res));
        
        return 0;
}