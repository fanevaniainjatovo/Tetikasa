#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

char *genermdp(int n);
int main(int argc, char **argv){

   printf("\t\tCREATION DE PROFIL D'UTILISATEUR SYSTEME\n");

   FILE* f=fopen("/etc/passwd","r+");   
   
   
  char tmp[255];
   
  int line=0;
  
  while(feof(f)!=1){	  
   fgets(tmp,255,f);
   line++;
   }
  
   fclose(f);
   
   char **user=malloc(sizeof(char*)*(line-1));
   f=fopen("/etc/passwd","r+");
  
  line=0;
  
  while(feof(f)!=1){
   user[line]=malloc(255);	  	  
   fgets(user[line],255,f);
   line++;
   } 
 
  
  char uti[line][30];
  char pwd[line][30];
  char UID[line][30];
  char GID[line][30];
  char group[line][30];
  char repus[line][30];
  char shell[line][30];
  
  FILE* file2=fopen("/home/faneva/user.csv","w+");
  
  fprintf(file2,"Nom d'utilisateur:Mot de passe:E-mail:Repertoire utilisateur:Shell\n\n");
  
  for(int j=0;j<line-1;j++){ 
	  sscanf(user[j],"%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]",uti[j],pwd[j],UID[j],GID[j],group[j],repus[j],shell[j]);
	  
	  if(atoi(UID[j])<=60000 && atoi(UID[j])>=1000){
		 char mail[40];
		 sprintf(mail,"%s@gmail.com",uti[j]);
		 fprintf(file2,"%s:%s:%s:%s:%s",uti[j],genermdp(10),mail,repus[j],shell[j]);
		 sleep(1);
		 }
	  }
	 
	 printf("FAIT"); 
     
   fclose(file2);
   fclose(f);
   
   return 0;

   }

char *genermdp(int n){
	
	srand(time(NULL));
	int a;
	
	n=5+(7*(float)(rand()))/(RAND_MAX+1.0);
	
	char* mdp=malloc(n);
	
	for(int i=0;i<n;i++){
		a=33+(93*(float)(rand()))/(RAND_MAX+1.0);
		mdp[i]=a;
		}
	
	return mdp;
	}
