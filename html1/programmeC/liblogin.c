#include "liblogin.h"

void connex(char* ins,char* mdp,char* mdp1){
	
	printf("<center><h1>Auth.log connexion</h1>");
    printf("<fieldset>");   
	printf("<form method=\"post\" action=\"./login.cgi\">");
	printf("<input type=\"text\" name=\"Nom\" placeholder=\"Nom\"></br></br>");
	printf("<input type=\"password\" name=\"Mdp\" placeholder=\"Mot de passe\"> </br></br>");		 
    
    
    if(strcmp(ins,"s`inscrire")==0 ){
    
    printf("<input type=\"password\" name=\"hda\" placeholder=\"Retaper le mot de passe\"> </br></br>");
    printf("<input class=\"bouton\" type=\"submit\" name=\"ins\"value=\"%s\">",ins);
	printf("<a href=\"http://www.cv.fr/cgi-bin/login.cgi\">Retour</a>");
	
     }
	
	else{
		
	printf("<input class=\"bouton\" type=\"submit\" value=\"se connecter\">");
	printf("<a href=\"http://www.cv.fr/cgi-bin/login.cgi?s`inscrire\">Creer un nouveau compte</a>");
		
		}
	
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
	
	con=fopen("../fic/connex","w");
	fprintf(con,"1");
	
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

void testconnex(char* op){
	
	FILE* con=fopen("../fic/connex","r");
    fgets(op,30,con);
		
	}
	
int countline(){
   
   FILE* f=fopen("/var/log/auth.log","r");
   int line=0;
   char tmp[255];
   while(feof(f)!=1){fgets(tmp,255,f);line++;}
	
	return line;
	}

void boutonA(int bouton,int l){
	
  int deb=(bouton>=5 && bouton<=l/10)?(bouton-4):1;
  int page=(l/10>10)?10:l/10+1;
  
  for(int i=0;i<page;i++){     
	   printf("<form action=\"./form.cgi\" method=\"get\">");
	   printf("<button type=\"submit\" name=\"bouton\"value=\"%d\">Page %d</button>",deb,deb);deb++;
	   if(deb>l/10+1){break;}
	   printf("</form>");
      
      }	
	
	}

void auth(){
	
  
  FILE* f=fopen("/var/log/auth.log","r");
  char *nom;
  char p[20];
  char us[20];
  FILE* fu;  
  int bouton=1,i=0,a=0; 
  char date[countline(f)][4][10];
  char session[countline(f)][20];
  char uti[countline(f)][10];
  char tsy[countline(f)][2][30];
  
  int l=0;
  char tmp1[255],o[100];
  
   char tus[50];
   char tsession[50];
   char tdate[3][50];
  
  
  nom=getenv("QUERY_STRING"); 
  sscanf(nom,"%[^=]=%s",p,us);
    
   if(strcmp(p,"user")==0){
	   fu=fopen("../fic/us","w");
	   fprintf(fu,"%s",us);
	   }
   	   
   else{bouton=atoi(us);}
   
   fu=fopen("../fic/us","r");
   fgets(us,20,fu);
  
  
  printf("<table border>");
  
  f=fopen("/var/log/auth.log","r");
 
  for(i=0;feof(f)!=1;i++){	  
    
    fgets(tmp1,255,f);
    if(strstr(tmp1,"for user")){
          		
        sscanf(tmp1,"%[^ ] %[^ ] %[^ ] %[^:]: %[^ ] session %[^ ] for user %[^ ] ",tdate[0],tdate[1],tdate[2],tsy[l][0],tsy[l][1],tsession,tus);  
         
       if(strcmp(us,tus)==0 || strcmp(us,tus)==-10){
		   strcpy(uti[l],tus);
	       strcpy(session[l],tsession);
	       for(a=0;a<3;a++){
	         strcpy(date[l][a],tdate[a]);
		      }
		     
	       l++;
	  
	      }
	      
       }
 
    }
  
  
  for(i=(bouton-1)*10;i<(bouton-1)*10+10;i++){
	         
	      if(i==(bouton-1)*10 && l>0){printf("<tr><td><B>Date et heure</B></td> <td><B>Session</B></td> <td><B>Utilisateur</B></td></tr>");}
				
				sprintf(o,"%s %s %s",date[i][0],date[i][1],date[i][2]);
				if(strcmp(session[i],"closed")==0){  
					printf("<tr><td>%s</td> <td style=\"color:red\">%s</td> <td>%s</td> </tr>",jourS(o),session[i],uti[i]);
				  }
	   
		        else if(strcmp(session[i],"opened")==0){
		            printf("<tr><td>%s</td> <td style=\"color:green\">%s</td><td>%s</td> </tr>",jourS(o),session[i],uti[i]);	
			      }
	           
	    } 		  
 	  
	  
  if(l==0){printf("<h2 style=\"color:#361447\">L' utilisateur que vous avez  saisi n'a pas encore ouvert de session ou n'existe pas</h2>");}
  else{boutonA(bouton,l);}
  
  printf("</table></center>"); 
  printf("<a href=\"./login.cgi\">Rechercher de nouveau</a>");
 
  printf("</body>"); 
  fclose(f);
     
     
     }
	
	
void deconnex(char* co){
	
	FILE* con=fopen("../fic/connex","r");
	fgets(co,30,stdin);
    
  if(strstr(co,"con")){con=fopen("../fic/connex","w");fprintf(con,"0");};
    
	printf("<form method=\"post\" action=\"./login.cgi\">");
	printf("<button class=\"connex\" type=\"submit\"name=\"con\" value=\"0\">Se deconnecter</button>");
	printf("</form>"); 
	
	}
