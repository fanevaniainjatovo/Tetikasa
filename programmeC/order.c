/*
 * order.c
 * 
 * Copyright 2023 faneva <faneva@faneva-Aspire-V5-571P>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc, char **argv)
{  
	int numRand=0;
	int numRand2=0;
	char lettreRand[3]={"TDL"};
    char tmp=0;
    char comp[3];
    char valiny[100];
  
	srand(time(NULL));
	for(int i=0;i<3;i++){
	    comp[i]=lettreRand[i];	
	    }
/*	for(int i=0;i<17;i++){
	    printf("%c",comp[i]);	
	    }  
	printf("\n");      
*/  
       
    while(lettreRand==comp){
    for(int i=0;i<57+numRand2;i++){
		
		numRand=((int)((3.0*rand())/(RAND_MAX +1.0)));	
	    numRand2=((int)((3.0*rand())/(RAND_MAX +1.0)));
	
	    tmp=lettreRand[numRand];
	    lettreRand[numRand]=lettreRand[numRand2];
	    lettreRand[numRand2]=tmp;
	    
	    }
	   }
	    printf("\n/");
	    for(int i=0;i<3;i++){
	    printf("%c/",lettreRand[i]);	
	    }
	
	     printf("\n\nReponse=>");
	fgets(valiny,100,stdin);
	//printf("%d\n",(strcmp(comp,valiny)+10));
	
	if((strcmp(comp,valiny)+10)==0){printf("Marina\n");}
	else{printf("diso");}    
	return 0;
}

