
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "css.c"

int countline(){
   
   FILE* f=fopen("/var/log/apache2/access.log","r");
   int line=0;
   char tmp[255];
   while(feof(f)!=1){fgets(tmp,255,f);line++;}

	return line;
	}


void boutonA(int bouton,int l){
	
  int deb=(bouton>=5 && bouton<=l/10)?(bouton-4):1;
  int page=(l/10>10)?10:l/10+1;
  
  for(int i=0;i<page;i++){     
	   printf("<form action=\"./access.cgi\" method=\"get\">");
	   printf("<button type=\"submit\" name=\"bouton\"value=\"%d\">page %d</button>",deb,deb);
	   deb++;
	   if(deb>l/10+1){break;}
	   printf("</form>");
      
      }	
	
	}
	

void access(int bouton){
	
  
  FILE* f=fopen("/var/log/apache2/access.log","r");
  char line[400];
  char ip[countline()][40];
  char date[countline()][40];
  char heure[countline()][40];
  char site[countline()][40];
  int i=0;
  int j=0;
 
    while(fgets(line,400,f)){
		sscanf(line,"%[^ ] %*[^[][%[^:]:%[^ ] %*[^/]/%*[^\"]\"%*[^\"]\"%[^\"]\"",ip[i],date[i],heure[i],site[i]);
		if(i>=(bouton-1)*10 && i<=(bouton-1)*10+10)
		printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>",ip[i],date[i],heure[i],site[i]); 
		    i++;
		   
		}
 
     }

int main(int argc, char **argv)
{
	char* nom=malloc(20);
	int bouton=1;
	
	nom=getenv("QUERY_STRING"); 
    sscanf(nom,"%*[^=]=%d",&bouton);
       
	printf("Content-type:text/html\n\n");
	css("../css/auth.css");
	printf("<center><table border>");
	access(bouton);
	boutonA(bouton,countline());
	printf("</table></center>");
	
	return 0;
}

