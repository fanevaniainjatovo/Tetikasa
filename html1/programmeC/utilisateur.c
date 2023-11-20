#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv){

   printf("Content-type:text/html\n\n");
   FILE* f=fopen("/etc/passwd","r");   
   FILE* css=fopen("/home/faneva/html1/css/auth.css","r");
   
  char tmp[255];
  char style;
   
   printf("<style type=text/css>\n");
   printf("<!--\n");
  
    while(style!=EOF){style=fgetc(css);printf("%c",style);}
    
    printf("\n-->");
    printf("</style>\n"); 
  
  printf("<center><table border>");
  printf("<tr><td><b>Utilisateur</b></td> <td><b>Repertoire Utilisateur</b></td> <td><b>Shell</b></td></tr>");
     while(feof(f)!=1){
	   
	   fgets(tmp,255,f);
		char uti[30];
		char pwd[30];
		char UID[30];
		char GID[30];
		char group[30];
		char repus[30];
		char shell[30];
   
	  sscanf(tmp,"%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]",uti,pwd,UID,GID,group,repus,shell);
	  
	  if(atoi(UID)<=60000 && atoi(UID)>=1000){
		 printf("<tr><td>%s</td> <td>%s</td> <td>%s</td></tr>",uti,repus,shell);		 
		 }
	  }
	 printf("</table></center>");
	      
   fclose(f);
   
   return 0;

   }
