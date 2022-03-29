/**
 * \file merge_sort.c
 * \brief Merge sort.
 * \date 2017
 * \author YOU
 * \copyright WTFPLv2
 */

/* Copyright © 2017 YOU <you@etu.unistra.fr>
 *
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar.
 *
 * See http://www.wtfpl.net/ or read below for more details.
 */
/* DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 * Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 */
#include "custom_sort.h"

#include "array.h"

////////////////////////////////////////////////////////////////////////////////
// Your implementation.
////////////////////////////////////////////////////////////////////////////////



long int* custom_sort(size_t size, long int* const array)
{
 

   mergesort(array,0,size-1);
  return array;
}

////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////
void merge(long int *const A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 =  r - q;
    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = A[q + 1 + j];
    
int i, j, k;
    i = 0;
    j = 0;
    k = p;

 while (i < n1 && j < n2)
 {
        if (L[i] <= M[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = M[j];
            j++;
        }
        //printf("%d\n",A[k] );
        k++;
}
 while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = M[j];
        j++;
        k++;
    }
}



void mergesort(long int *const a,int p,int r)
{
    if(p >= r)
        return;
    else{

        int q = (p+r)/2;
        mergesort(a, p, q);
        mergesort(a, q+1, r);
        //printf("%d %d    %d %d\n",p ,q,q+1, r );
        merge(a, p, q, r);
    }

}

const char* custom_sort_name(void)
{
  return "merge_sort()";
}
