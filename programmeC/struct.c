

#include <faneva.h>

 typedef struct ID{
		char nom[50];
		char prenom[50];
		int age;
		float poids;
		float hauteur;
		}ID;
		
int main(int argc, char **argv)

{   struct ID identity;	
	
	strcpy(identity.nom,"Randrianantoandro");
    strcpy(identity.prenom,"Fanevaniainjatovo");
	identity.age=9; 
	identity.poids=61.4;
	identity.hauteur=175.67;
	
	
	printf("Bonjour %s %s \n%d ans %f kg et %f cm de long",identity.nom,identity.prenom,identity.age,identity.poids,identity.hauteur);
    
			
	return 0;
}

