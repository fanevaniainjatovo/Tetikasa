


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/faneva/programmeC/Machine.h"
#define nb 7
int main(int argc, char **argv){
	
    
    FILE* f=fopen("/home/faneva/milay.csv","w+");	
	Machine* pc=(Machine* )malloc(sizeof(Machine)*nb);
	    
	    fprintf(f,"Marque:Adresse mac:Label\n\n");
	    
	for(int i=0;i<nb;i++){
		printf("Marque %d=",i);scanf("%s",pc[i].marque);
	  	printf("Mac %d=",i);scanf("%s",pc[i].mac);
		printf("Label %d=",i);scanf("%s",pc[i].label);
		printf("\n\n");
		}
   
    tri(pc,nb);	
	
	for(int i=0;i<nb;i++){
		fprintf(f,"%s:%s:%s\n",pc[i].marque,pc[i].mac,pc[i].label);
		}
	 
	printf("Fait"); 
	 
	fclose(f);
	return 0;
}


