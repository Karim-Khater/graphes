// fichier arbre234.c

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include "arbre234.h"

// préc : aucune
// post : retourne l'arbre vide
// modif : aucune
Arb234 ba_vide()
{
   return (Arb234) NULL;
}
// description : enracinement avec une racine à une valeur
// préc ba_enrac1(f1, r1, f2) = ba_hauteur(f1) == ba_hauteur(f2)
// modif : allocation d'une structure strNode
Arb234 ba_enrac1(Arb234 f1, S r1, Arb234 f2)
{
   Arb234 res = (Arb234)malloc(sizeof(strNode));
   res->type = type2fils;
   res->val1 = r1;
   res->fils1 = f1;
   res->fils2 = f2;
   return res;
}
// description : enracinement avec une racine à deux valeurs
// préc ba_enrac1(f1, r1, f2, r2, f3) =
// ba_hauteur(f1) == ba_hauteur(f2) == ba_hauteur(f3)
// modif : allocation d'une structure strNode
Arb234 ba_enrac2(Arb234 f1, S r1, Arb234 f2, S r2, Arb234 f3)
{
   Arb234 res = (Arb234)malloc(sizeof(strNode));
   res->type = type3fils;
   res->val1 = r1;
   res->val2 = r2;
   res->fils1 = f1;
   res->fils2 = f2;
   res->fils3 = f3;
   return res;
}
// description : enracinement avec une racine à trois valeurs
// préc ba_enrac1(f1, r1, f2, r2, f3, r3, f4) =
//   ba_hauteur(f1) == ba_hauteur(f2) == ba_hauteur(f3) == ba_hauteur(f4)
// modif : allocation d'une structure strNode
Arb234 ba_enrac3(Arb234 f1, S r1, Arb234 f2,S r2, Arb234 f3, S r3, Arb234 f4)
{
   Arb234 res = (Arb234)malloc(sizeof(strNode));
   res->type = type4fils;
   res->val1 = r1;
   res->val2 = r2;
   res->val3 = r3;
   res->fils1 = f1;
   res->fils2 = f2;
   res->fils3 = f3;
   res->fils4 = f4;
   return res;
}

// préc ba_f1(b) = not ba_estvide(b)
// post : retourne le premier fils
// modif ; aucune
Arb234 ba_f1(Arb234 b)
{
   return b->fils1;
}
// préc ba_f2(b) = true
// post :retourne le
// modif ; aucune
Arb234 ba_f2(Arb234 b)
{
   return b->fils2;
}


// préc ba_f3(b) = ba_ntype(b) != type2fils
// post :retourne le deuxième fils
// modif ; aucune
Arb234 ba_f3(Arb234 b)
{
   return b->fils3;
}

// préc ba_f4(b) = ba_ntype = type4fils
// post :retourne le troisième fils
// modif ; aucune
Arb234 ba_f4(Arb234 b)
{
   return b->fils4;
}

bool ba_estvide(Arb234 b)
{
        return b == NULL;
}

bool ba_2f(Arb234 b)
{
  return (b->fils2)!=NULL;
}
bool ba_3f(Arb234 b)
{
  return (b->fils3)!=NULL;
}
bool ba_4f(Arb234 b)
{
  return (b->fils4)!=NULL;
}

S ba_r1(Arb234 b)
{
  return b->val1;
}
S ba_r2(Arb234 b)
{
  return b->val2;
}
S ba_r3(Arb234 b)
{
  return b->val3;
}
void ba_print(Arb234 b)
{
   ba_print_aux(b,0);
}
void ba_print_aux(Arb234 b, Nat prof)
{
   if(!b) {
             for(int i=0; i<(int)prof; i++) printf("   ");
             printf("   <|\n"); return;
           }
   ba_print_aux(b->fils1, prof+2);
   for(int i=0; i<(int)prof; i++) printf("   ");
   printf("|: %3d\n", b->val1);
   ba_print_aux(b->fils2, prof+2);
   if(b->type > type2fils)
   {
       for(int i=0; i<(int)prof; i++) printf("   ");
       printf("|: %3d\n", b->val2);
       ba_print_aux(b->fils3, prof+2);
       if(b->type > type3fils)
       {
           for(int i=0; i<(int)prof; i++) printf("   ");
           printf("|: %3d\n", b->val3);
           ba_print_aux(b->fils4, prof+2);
       }
   }

}
// modif : aucune
Arb234 ba_app(S x, Arb234 b)
{
   if(!b) return ba_vide();
   switch (b->type)
   {
   case type4fils :
       if(x > b->val3) return ba_app(x, b->fils4);
       if(x == b->val3) return b;
   case type3fils :
       if(x > b-> val2) return ba_app(x,b->fils3);
       if(x == b->val2) return b;
   default :
       if(x > b-> val1) return ba_app(x,b->fils2);
       if(x == b->val1) return b;
       return ba_app(x, b->fils1);
   }
}
Nat max(unsigned a, unsigned b)
{
  return a < b ?b :a;
}
Nat ba_hauteur(Arb234 a)
{
        unsigned h1,h2,h3,h4;
        if(!a)
                return 0 ;
        else{
                if(a->type == type2fils){
                        h1 = ba_hauteur(a->fils1) + 1;
                        h2 = ba_hauteur(a->fils2) + 1;
                        return max(h1,h2);
                }
                else if(a->type == type3fils){
                        h1 = ba_hauteur(a->fils1) + 1 ;
                        h2 = ba_hauteur(a->fils2) + 1 ;
                        h3 = ba_hauteur(a->fils3) + 1 ;
                        return max(max(h1,h2),h3);
                }
                else{
                        h1 = ba_hauteur(a->fils1) + 1 ;
                        h2 = ba_hauteur(a->fils2) + 1 ;
                        h3 = ba_hauteur(a->fils3) + 1 ;
                        h4 = ba_hauteur(a->fils4) + 1 ;
                        return max(max(h1,h2),max(h4,h3));
                }
        }
}
//pre x> v1 et v2
Arb234 ba_insertion(Arb234 a,S x,struct node * fils5)
{
 
  if(!a)
    return 0;
  else{
      if(a->type==type2fils)
      {
        a->type= type3fils;
          if(a->val1>x)
            {
            a->val2=a->val1;
            a->val1=x;
            a->fils3=a->fils2;
            a->fils2=a->fils1;
            a->fils1=fils5;
           }
          else{
             a->val2=x;
             a->fils3=fils5;
           }
      }
      else if(a->type== type3fils)
      {
        a->type= type4fils;
          if(a->val2>x){
              a->val3= a->val2;
              a->val2=x;
              a->fils4=a->fils3;
              
                if(a->val1>x)
                {
                  a->fils3=a->fils2;
                  a->fils2=a->fils1;
                  a->fils1=fils5;
                }
                else{
                  a->fils3=a->fils2;
                  a->fils2=fils5;
                }
            }
            else{
              a->val3=x;
              a->fils4=fils5;
            }
      }
      else
      {
        Arb234 tmp1=ba_enrac1(a->fils1,a->val1,a->fils2);
        Arb234 tmp2=ba_enrac1(a->fils3,a->val3,a->fils4);
        Arb234 tmpx=ba_enrac2(tmp1,a->val2,tmp2,x,fils5);
      }
  }
}
int main(int argc, char const *argv[]) {
        (void)argc;
        (void)argv;
        Arb234 a1 = ba_enrac2(NULL,5,NULL,7,NULL);
        Arb234 a2 = ba_enrac1(NULL,9,NULL);
        Arb234 a3 = ba_enrac2(NULL,12,NULL,13,NULL);
        Arb234 a4 = ba_enrac1(NULL,20,NULL);
        Arb234 a5 = ba_enrac3(a1,8,a2,10,a3,15,a4);
        ba_print(a5);

        return 0;
}
