
typedef struct Machine{
	char marque[30];
	char mac[30];
	char label[30];
	
	}Machine;

typedef struct Eleve{
	
	char nom[30];
	char prenom[30];
	char numero[11];
	char email[40];
	char adresse[30];
    char dnaissance[20];
	char lnaissance[20];
	int annee;
	char sexe[1];
	char CIN[13];
	char url[50];
	
	}Eleve;

void tri(Eleve* label,int nbrM);	
