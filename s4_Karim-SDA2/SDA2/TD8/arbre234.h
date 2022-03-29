// fichier arbre234.h
#ifndef __ARBRE234_H__
#define __ARBRE234_H__
#include<stdbool.h>

typedef unsigned Nat;
typedef int S;
typedef enum { type2fils=1, type3fils, type4fils} node_type;

typedef struct node {
    node_type type;        // type du noeud 2, 3 ou 4
    struct node *fils1;    // 1er fils
    S val1;            // 1ère racine
    struct node *fils2;    // etc.
    S val2;
    struct node *fils3;
    S val3;
    struct node *fils4;
                    } strNode, *Arb234;


// préc : aucune
// post : retourne l'arbre vide
// modif ; aucune
Arb234 ba_vide();

// description : enracinement avec une racine à une valeur
// préc ba_enrac1(f1, r1, f2) = ba_hauteur(f1) ==  ba_hauteur(f2)
// post : retourne un arbre 234 avec une racine à 1 valeur : r1
//                      et deux ss-arbres f1 et f2
// modif : allocation d'une structure strNode
Arb234 ba_enrac1(Arb234 f1, S r1, Arb234 f2);

// description : enracinement avec une racine à deux valeurs
// préc ba_enrac1(f1, r1, f2, r2, f3) = ba_hauteur(f1) == ba_hauteur(f2)
//                                        == ba_hauteur(f3)
// post : retourne un arbre 234 avec une racine à 2 valeurs : r1 et r2
//                              et trois ss-arbres f1, f2 et f3
// modif : allocation d'une structure strNode
Arb234 ba_enrac2(Arb234 f1, S r1, Arb234 f2, S r2, Arb234 f3);

// description : enracinement avec une racine à trois valeurs
// préc ba_enrac1(f1, r1, f2, r2, f3, r3, f4) =
//       ba_hauteur(f1) == ba_hauteur(f2) == ba_hauteur(f3) == ba_hauteur(f4)
// post : retourne un arbre 234 avec une racine à 3 valeur : r1, r2 et r3
//                                  et quatre ss-arbres f1, f2, f3 et f4
// modif : allocation d'une structure strNode
Arb234 ba_enrac3(Arb234 f1, S r1, Arb234 f2,S r2, Arb234 f3, S r3, Arb234 f4);

// description : test de vacuité
// préc : aucune
// post : true si b est l'arbre vide, false sinon
// modif : aucune
bool ba_estvide(Arb234 b);


// préc : aucune
 // post : retourne le le type du noeud type2fils ou type3fils ou type4fils
// modif ; aucune
node_type ba_ntype(Arb234 b);


// préc ba_f1(b) = not ba_estvide(b)
// post : retourne le premier fils
// modif ; aucune
Arb234 ba_f1(Arb234 b);

// préc ba_f2(b) = not ba_estvide(b)
// post :retourne le premier fils
// modif ; aucune
Arb234 ba_f2(Arb234 b);

// préc ba_f3(b) = ba_ntype >= type3fils &&not ba_estvide(b)
// post :retourne le deuxième fils
// modif ; aucune
Arb234 ba_f3(Arb234 b);

// préc ba_f4(b) = ba_ntype == type4fils && = ba_estvide(b)
// post :retone le troisième fils
// modif ; aucune
Arb234 ba_f4(Arb234 b);

// préc ba_hauteur(b) = b est un arbre 234 : toutes
//                      les branches ont la même longueur
// post : retourne la hauteur de b
// modif : aucune
Nat ba_hauteur(Arb234 b);

// affichage sans fioriture pour pouvoir faire des test
void ba_print(Arb234 b);
void ba_print_aux(Arb234 b, Nat prof);

// affichage par ordre croissant des valeurs stockées dans l'arbre
// préc : aucune
// modif : affichage
void ba_print_val(Arb234 b);
S ba_r1(Arb234 b);
S ba_r2(Arb234 b);
S ba_r3(Arb234 b);
bool ba_2f(Arb234 b);
bool ba_3f(Arb234 b);
bool ba_4f(Arb234 b);
Arb234 ba_insertion(Arb234 a,S x, struct node * fils5);
//////////////////////////////
// recherche

// préc aucune
// post : un arbre dont la racine contient x, NULL si x n'apparaît pas dans b
// modif : aucune
Arb234 ba_app(S x, Arb234 b);
#endif
