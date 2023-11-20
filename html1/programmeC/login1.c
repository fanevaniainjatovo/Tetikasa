
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "css.c"


void connex(){
	
	printf("<center><h1>Auth.log connexion</h1>");
    printf("<fieldset>");   
	printf("<form method=\"post\" action=\"./login1.cgi\">");
	printf("<input type=\"text\" name=\"Nom\" placeholder=\"Nom\"></br></br>");
	printf("<input type=\"password\" name=\"Mdp\" placeholder=\"Mot de passe\"> </br></br>");		 
    
    
   /* if(strcmp(ins,"s`inscrire")==0 ){
    
    printf("<input type=\"password\" name=\"hda\" placeholder=\"Retaper le mot de passe\"> </br></br>");
    printf("<input class=\"bouton\" type=\"submit\" name=\"ins\"value=\"%s\">",ins);
	printf("<a href=\"http://www.cv.fr/cgi-bin/login.cgi\">Retour</a>");
	
     }*/
	
//	else{
		
	printf("<input class=\"bouton\" type=\"submit\" value=\"se connecter\">");
//	printf("<a href=\"http://www.cv.fr/cgi-bin/login.cgi?s`inscrire\">Creer un nouveau compte</a>");
		
	//	}
	
	printf("</form>");
	printf("</fieldset>");
	printf("</center>");
	
	
	}
	

void recherche(){
	
	printf("<center>");
    
    FILE* con=fopen("../fic/connex","r");	
 	FILE* uslog=fopen("../fic/uslog","r");
 	char nom[30];
 	fgets(nom,30,uslog);
 	fgets(nom,30,uslog);
 	
	printf("<h1>Recherche d'utilisateur</h1>");
	printf("<div><center><span>%c</span></center></br>%s</div>",nom[0],nom);    
    printf("<fieldset>");
    printf("<form method=\"get\" action=\"./form.cgi\">");
	printf("<input placeholder=\"Nom d'utilisateur\" type=\"text\" name=\"user\">");
	printf("<input class=\"recherche\" type=\"submit\" value=\"\">");
	printf("</form>");
	printf("</center>");
	printf("</fieldset>");
	
	printf("<form method=\"post\" action=\"./login.cgi\">");
	printf("<button class=\"connex\" type=\"submit\"name=\"con\" value=\"0\">Se deconnecter</button>");
	printf("</form>");
	
	}	

void testlogin(char* logfic,char* nom,char* log){
	
	FILE* f=fopen("../fic/login","a+");
	FILE* uslog;
	
	while(feof(f)!=1){
	
	fgets(logfic,50,f);
	logfic[strlen(logfic)-1]='\0';
	
	if(strcmp(logfic,log)==0){
		uslog=fopen("../fic/uslog","w");
	    fprintf(uslog,"%s",nom);
	    fclose(uslog);
		break;
		}  

     }
	
	}

int main(int argc, char **argv)

{   
	char logfic[70],log[70],tsy[2][10],nom[20],mdp[20];
	
	fgets(log,50,stdin);   
    sscanf(log,"%[^=]=%[^&]&%[^=]=%[^\n]",tsy[0],nom,tsy[1],mdp);
	testlogin(logfic,nom,log);
    	
	sprintf(log,"%s:%s",nom,mdp);
	
	if(strcmp(log,logfic)==0 ){
	    
	    printf("Content-type: text/html\n\n");
		css("../css/auth.css");
		connex();
	    
       }
    
    else{
		
		
		printf("Location: http://www.cv.fr/cgi-bin/form.cgi\n\n");
		
		}
       
	
	return 0;
}

