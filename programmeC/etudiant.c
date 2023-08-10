
#include <stdio.h>
#include <string.h>

typedef struct Eleve{
	
	char nom[30];
	char prenom[30];
	int numero;
	int age;
	float taille;
	int masse;
	char email[40];
	char url[50];
	
	}Eleve;


int main(int argc, char **argv){
	
	FILE* f=fopen("/home/faneva/etudiant.csv","w+");
	
	Eleve faneva={"Randrianantoandro","Fanevaniainjatovo",30,19,1.75,65,"654.faneva@gmail.com","https://github.com/fanevaniainjatovo/Tetikasa/"};
	
	fprintf(f,"NOM;PRENOM;NUMERO;AGE(ans);TAILLE(m);MASSE(kg);E-MAIL;URL\n\n");
	fprintf(f,"%s;%s;%d;%d;%f;%d;%s;%s\n",faneva.nom,faneva.prenom,faneva.numero,faneva.age,faneva.taille,faneva.masse,faneva.email,faneva.url);
	
	fclose(f);
	return 0;
    }


 
