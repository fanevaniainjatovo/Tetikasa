

#include <stdio.h>

int main(int argc, char **argv)
{
	int base;
	int hauteur;
	
	printf("Base=");
	scanf("%d",&base);
	printf("Hauteur=");
	scanf("%d",&hauteur);
	
	int max=(base>=hauteur)?base:hauteur;
	
	for(int i=0;i<max;i++){
	    for(int j=i;j<max;j++){printf(" ");}
	    for(int j=0;j<i;j++){printf("*");}
	 
	    printf("\t");
	 
	    for(int j=0;j<i;j++){printf("*");}	
	    for(int j=i;j<max;j++){printf(" ");}
	    printf("\n");
	   
	   }
	
	
   	return 0;
}

