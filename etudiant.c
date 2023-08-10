
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/home/faneva/programmeC/Machine.h"

#define nb 4


int main(int argc, char **argv){
	
	FILE* f=fopen("/home/faneva/info_Etudiant.csv","a+");
	
		Eleve* mit=(Eleve* )malloc(sizeof(Eleve)*nb);
	    
	    fprintf(f,"Nom:Prenom:Numero de telephone:E-mail:Adresse:Date de naissance:Lieu de naissance:Annee d'obtention bacc:Sexe:CIN:url\n\n");
	    
	for(int i=0;i<nb;i++){
		
		printf("Nom %d=",i);scanf("%s",mit[i].nom);
		printf("Prenom %d=",i);scanf("%s",mit[i].prenom);
		printf("Numero de telephone %d=",i);scanf("%s",mit[i].numero);
		printf("E-mail %d=",i);scanf("%s",mit[i].email);
		printf("Adresse %d=",i);scanf("%s",mit[i].adresse);
		printf("Date de naissance %d=",i);scanf("%s",mit[i].dnaissance);
		printf("Lieu de naissance %d=",i);scanf("%s",mit[i].lnaissance);
		printf("Annee d'obtention du bacc %d=",i);scanf("%d",&mit[i].annee);
		printf("Sexe %d=",i);scanf("%s",mit[i].sexe);
		printf("CIN %d=",i);scanf("%s",mit[i].CIN);
		printf("URL git %d=",i);scanf("%s",mit[i].url);
			
		}
   
   
   tri(mit,nb);	
	
	for(int i=0;i<nb;i++){
		fprintf(f,"%s:%s:%s:%s:%s:%s:%s:%d:%s:%s:%s\n",
		mit[i].nom,mit[i].prenom,mit[i].numero,mit[i].email,mit[i].adresse,mit[i].dnaissance,
		mit[i].lnaissance,mit[i].annee,mit[i].sexe,mit[i].CIN,mit[i].url);
		}
		
	printf("Fait");
	
	fclose(f);
	return 0;
    
    }


 
