
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "liblogin.c"
#include "css.c"
#include "andro.c"

int main(){
  
  printf("Content-type:text/html\n\n"); 
  printf("<body>");
  
  char* ins;
  char log[70];
  char nom[30],mdp[30],mdp1[30];
  char tsy[3][30];
  FILE* f;
  FILE* con;
  FILE* uslog;
  char co[3];
  char logfic[50];
  
  css("../css/auth.css");
  
  ins=getenv("QUERY_STRING");
  
  fgets(log,50,stdin);   
  sscanf(log,"%[^=]=%[^&]&%[^=]=%[^\n]",tsy[0],nom,tsy[1],mdp);
  
  f=fopen("../fic/login","a+");
  
  if(strstr(mdp,"ins")==NULL){sprintf(log,"%s:%s",nom,mdp);}
  else{
	  sscanf(mdp,"%[^&]&%[^=]=%[^\n]",mdp,tsy[2],mdp1);
	  sprintf(log,"%s:%s",nom,mdp);
	
	    fprintf(f,"%s\n",log);
	  
	  } 
  
   
  con=fopen("../fic/connex","r");
  
  if(strcmp(tsy[0],"con")==0){con=fopen("../fic/connex","w");strcpy(log,"cjjh");fprintf(con,"0");}
 
  fgets(co,3,con);
   
   
   testlogin(logfic,nom,log);
 
   if(strcmp(log,logfic)==0 || atoi(co)==1){
    	
	   recherche();
	   
	   }
	   
   else{
	
	   connex(ins,mdp,mdp1);
    
       }
       
  printf("</body>");
       
  fclose(f); 
  fclose(con);
  
   return 0;
 }
