
#include <faneva.h>

int compare(char* artiste,char* artisteListe);

int main(int argc, char **argv)
{   
	
	while(1){



miverina:
	printf("\t\t\t\033[36mCONFIGURATION VAZO MISOMA\033[0m\n\n");
	printf("\033[33m1--\033[0mConfigurer 'Lyrics Translating'\n\033[33m2--\033[0mConfigurer 'Singer's name re-ordering'\n\033[33m3--\033[0mConfigurer 'Guess the song'\n");
    printf("\033[33m4--\033[0mQuitter CONFIGURATION VAZO MISOMA\n");
    int choix=0;
    char corb[20];
    
    printf("\nEntrez votre choix\033[33m(le numero)\033[0m\n=>");
    
    int scan=scanf("%d",&choix);
		if(scan==0){scanf("%s",corb);}
    
    if(choix==1){
		system("clear");
	    printf("\t\t\t\033[36mCONFIGURATION VAZO MISOMA:'Lyrics Translating'\033[0m\n\n");  	
		
		
		printf("	\033[33m~~\033[0m Modifier le nombre de coups par défaut\n\n");
		
		char cmd1[50];
		sprintf(cmd1,"cat ~/Lyrics_conf");
		
		
		FILE *fd=popen(cmd1,"r");
		
		char couptmp1[50];
		fgets(couptmp1,50,fd);
		int coupLyrics=atoi(couptmp1);
		
		printf("\033[33m==>\033[0mCOUPS PAR DEFAUT = \033[33m%d\033[0m coups\n",coupLyrics);
		
		printf("\033[33m==>\033[0mEntrez nouveau coup: ");
		scan=scanf("%d",&coupLyrics);
		if(scan==0){scanf("%s",corb);}
		
		char edit[50];
		sprintf(edit,"echo %d > ~/Lyrics_conf",coupLyrics);
		system(edit);
		fclose(fd);
		system("clear");
	
		}
    	
	
	else if(choix==2){
		system("clear");
		
		while(1){
			
		int incr=0;	
eto:	printf("\t\t\t\033[36mCONFIGURATION VAZO MISOMA:'Singer's name re-ordering'\033[0m\n\n");
		 
		
		printf(" \033[33m1 ~~\033[0m Modifier le nombre de coups par défaut\n");
		printf(" \033[33m2 ~~\033[0m Ajouter des artistes supplémentaires au jeu\n");
		printf(" \033[33m3 ~~\033[0m Quitter CONFIGURATION VAZO MISOMA:'Singer's name re-ordering'\n\n");
		
	    printf("Entrez votre choix\033[33m(le numero)\033[0m\n=>");
        
        int choice=0;
        int scan=scanf("%d",&choice);
		if(scan==0){scanf("%s",corb);}
		
		system("clear");
		
		if(choice==1){
			char cmd1[50];
			printf("\t\t\t\033[36mCONFIGURATION VAZO MISOMA:'Singer's name re-ordering'\033[0m\n\n");
			sprintf(cmd1,"cat ~/Order_conf");
		
		
			FILE *fd=popen(cmd1,"r");
		
			char couptmp2[50];
			fgets(couptmp2,50,fd);
			int coupOrder=atoi(couptmp2);
		
			printf("\033[33m==>\033[0mCOUPS PAR DEFAUT = \033[33m%d\033[0m coups\n",coupOrder);
		
			printf("\033[33m==>\033[0mEntrez nouveau coup: ");
			scan=scanf("%d",&coupOrder);
			if(scan==0){scanf("%s",corb);}
		
			char edit[50];
			sprintf(edit,"echo %d > ~/Order_conf",coupOrder);
			system(edit);
			fclose(fd);
			system("clear");
			
			}
			
	   else if(choice==2){
			
			char cmdNombreArtiste[60];
			char NATmp[2];
			int nombreArtiste=0;
			
   here:   	printf("\t\t\t\033[36mCONFIGURATION VAZO MISOMA:'Singer's name re-ordering'\033[0m\n\n");
			printf("Voici les artistes existants en ce moment:\n\n");
			
			sprintf(cmdNombreArtiste,"wc -l ~/vazoMisoma/usr/local/fichier/valin-korontana");
		    FILE *fd=popen(cmdNombreArtiste,"r");
		    fgets(NATmp,100,fd);
		    nombreArtiste=atoi(NATmp);
			
			char **artisteListe=malloc(sizeof(char*)*nombreArtiste);
				for(int i=0;i<nombreArtiste;i++){artisteListe[i]=malloc(30);}
				
			char **cmdArtiste=malloc(sizeof(char*)*nombreArtiste);
				for(int i=0;i<nombreArtiste;i++){cmdArtiste[i]=malloc(60);}
			
			FILE *fk;
			for(int i=0;i<nombreArtiste;i++){
				sprintf(cmdArtiste[i],"head  -%d ~/vazoMisoma/usr/local/fichier/valin-korontana | tail -1",i+1);
				fk=popen(cmdArtiste[i],"r");
				fgets(artisteListe[i],30,fk);
				printf(" \033[33m%d\033[0m- %s",i+1,artisteListe[i]);
				}
			
			fclose(fk);
			fclose(fd);	
			
			printf("\nEntrez un \033[33martiste\033[0m qui \033[33mn'\033[0mest \033[33mpas\033[0m dans la \033[33mliste\033[0m\n=>");
        
			char artiste[30];
			if(incr==0){fgets(artiste,30,stdin);}
			fgets(artiste,30,stdin);
			
			for(int i=0;i<nombreArtiste;i++){
				if(compare(artiste,artisteListe[i])==0){
					printf("\033[5;31mERREUR:Artiste déja présent!!!!\033[0m\n");
					sleep(2);
					system("clear");
					incr++;
					goto here;
					}
				}
							
            
			char edit[100];
			artiste[strlen(artiste)-1]='\0';
			sprintf(edit,"echo %s >> ~/vazoMisoma/usr/local/fichier/valin-korontana",artiste);
			system(edit);
			
			printf("\nEntrez une chanson de l'artiste (ou du groupe)\033[33m'%s'\033[0m\n=>",artiste);
			fgets(artiste,30,stdin);
			
			char editIndice[100];
			artiste[strlen(artiste)-1]='\0';
			
			sprintf(editIndice,"echo %s >> ~/vazoMisoma/usr/local/fichier/indiceKorontana",artiste);
			system(editIndice);
			
			system("clear");
			
			
			
			}	
         	
	   else if(choice==3){break;}
	   
	   else{
		printf("\033[5;31mERREUR:option introuvable!!!!\033[0m\n");
			sleep(2);
			system("clear");
		goto eto;
		}
	  
	  } 
	  
	}
		
		
    else if(choix==3){
		system("clear");
		while(1){
		
		
toerana:
		printf("\t\t\t\033[36mCONFIGURATION VAZO MISOMA:'Guess the song'\033[0m\n\n");
		 
		
		printf(" \033[33m1 ~~\033[0m Modifier le nombre de coups par défaut\n");
		printf(" \033[33m2 ~~\033[0m Modifier la durée de la chanson jouée\n");
		printf(" \033[33m3 ~~\033[0m Quitter CONFIGURATION VAZO MISOMA:''Guess the song''\n\n");
		
	    printf("Entrez votre choix\033[33m(le numero)\033[0m\n=>");
        
        int choice=0;
        int scan=scanf("%d",&choice);
		if(scan==0){scanf("%s",corb);}
		
		if(choice==1){
			system("clear");
			char cmd1[50];
			printf("\t\t\t\033[36mCONFIGURATION VAZO MISOMA:'Guess the song'\033[0m\n\n");
			sprintf(cmd1,"cat ~/Song_conf");
		
		
			FILE *fd=popen(cmd1,"r");
		
			char couptmp2[50];
			fgets(couptmp2,50,fd);
			int coupSong=atoi(couptmp2);
		
			printf("\033[33m==>\033[0mCOUPS PAR DEFAUT = \033[33m%d\033[0m coups\n",coupSong);
		
			printf("\033[33m==>\033[0mEntrez nouveau coup: ");
			scan=scanf("%d",&coupSong);
			if(scan==0){scanf("%s",corb);}
		
			char edit[50];
			sprintf(edit,"sed -i 1c\%d ~/Song_conf",coupSong);
			system(edit);
			fclose(fd);
			
			}
        
        else if(choice==2){
			system("clear");
			char cmd1[50];
			printf("\t\t\t\033[36mCONFIGURATION VAZO MISOMA:'Guess the song'\033[0m\n\n");
			sprintf(cmd1,"tail -1 ~/Song_conf");
			
			FILE *fd=popen(cmd1,"r");
		
			char Dtmp[50];
			fgets(Dtmp,50,fd);
			int Dt=atoi(Dtmp);
		
			printf("\033[33m==>\033[0mDUREE PAR DEFAUT = \033[33m%d\033[0m secondes\n",Dt);
		
			printf("\033[33m==>\033[0mEntrez nouvelle durée: ");
			scan=scanf("%d",&Dt);
			if(scan==0){scanf("%s",corb);}
			
			char edit[50];
			sprintf(edit,"sed -i 2c\%d ~/Song_conf",Dt);
			system(edit);
			fclose(fd);
			
			}
			
					
		else if(choice==3){system("clear");break;}
		
		else{
		printf("\033[5;31mERREUR:option introuvable!!!!\033[0m\n");
			sleep(2);
			system("clear");
		    goto toerana;
		    }
		
		
	    
		
		system("clear");
		
		}		
	}
	else if(choix==4){exit(0);}
	
	else{
		printf("\033[5;31mERREUR:option introuvable!!!!\033[0m\n");
			sleep(2);
			system("clear");
		goto miverina;
		}
		
 }	
 
 
 
 
	return 0;
}

 int compare(char* artiste,char* artisteListe){
	
	char tabArtiste[30];
	char tabArtisteListe[30]; 
	
	int f=0;
		for(int i=0;(i<=strlen(artiste));i++){
			if(((*(artiste+i)<='Z')&&(*(artiste+i)>='A'))||((*(artiste+i)<='z')&&(*(artiste+i)>='a'))){
				(*(tabArtiste+f))=(toupper(*(artiste+i)));
				f++;

			  }
		   }
		
	int j=0;
		for(int i=0;(i<strlen(artisteListe));i++){
			if(((*(artisteListe+i)<='Z')&&(*(artisteListe+i)>='A'))||((*(artisteListe+i)<='z')&&(*(artisteListe+i)>='a'))){
				(*(tabArtisteListe+j))=(toupper(*(artisteListe+i)));
				j++;
			  
			  }
		   }
	
	int k=0;
		for(int i=0;i<f;i++){
			if( (*(tabArtisteListe+i))==(*(tabArtiste+i)) ){
				k++;
			  }
		   }
	
	
	if(k==f){return 0;}
	else{return -1;}
	
	}
