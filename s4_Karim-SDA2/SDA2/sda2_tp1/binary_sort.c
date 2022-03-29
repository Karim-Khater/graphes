/**
 * \file binary_sort.c
 * \brief Binary sort.
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

#include <string.h>
#include "array.h"

////////////////////////////////////////////////////////////////////////////////
// Your implementation.
////////////////////////////////////////////////////////////////////////////////


long int* custom_sort(size_t size, long int* const array)
{
  
  int j,loc;
  long int* const result = malloc(size * sizeof *result);
  for (size_t i = 0; i < size; i++)
  {
  	j=i;
  	loc = dico(result,array[i],0,i);
  	while(j>loc)
  	{
  		result[j]=result[j-1];
  		j--;
  	}
  	result[loc]=array[i];
  }
  free(array);
  return result;
}

////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

int dico(long int* const array,long int x,int start,int end)
{
	
		int mid=(start+end)/2;

		if(array[mid]==x)
		{
			return mid;
		}
		else if (start==end)
		{
			return start;
		}
		else if(array[mid]>x)
		{
			return dico(array,x,start,mid);
		}
		
		else
		{
			return dico(array,x,mid+1,end);
		}
		
	
	
}

const char* custom_sort_name(void)
{
  return "binary_sort()";
}
