
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	
   printf("Content-type:text/html\n\n");
   
   FILE* f=fopen("/var/log/auth.log","r");   
   FILE* css=fopen("/home/faneva/html1/css/auth.css","r");
   
   
  char tmp[255];
  char style;
  
    printf("<style type=text/css>\n");
    printf("<!--\n");
  
    while(style!=EOF){style=fgetc(css);printf("%c",style);}
    
    printf("\n-->");
    printf("</style>\n"); 
    
    printf("<center><table border>");
    printf("<tr><td><B>Date et heure</B></td> <td><B>Session</B></td> <td><B>Utilisateur</B></td></tr>");
  while(feof(f)!=1){	  
    
    fgets(tmp,255,f);
    char date[4][10];
    char session[20];
    char uti[10];
    char tsy[2][30];
    
    if( strstr(tmp,"opened") || strstr(tmp,"closed") ){
		sscanf(tmp,"%[^ ] %[^ ] %[^ ] %[^:]: %[^ ] session %[^ ] for user %[^ ] ",date[0],date[1],date[2],tsy[0],tsy[1],session,uti);
	     
	    if(strcmp(session,"closed")==0){  
	    printf("<tr><td>%s %s %s</td> <td style=\"color:red\">%s</td> <td>%s</td> </tr>",date[0],date[1],date[2],session,uti);
	       }
	   
	    else{
		printf("<tr><td>%s %s %s</td> <td style=\"color:green\">%s</td><td>%s</td> </tr>",date[0],date[1],date[2],session,uti);	
			}
	   }
   
     }
     printf("</table></center>");
  fclose(f);
  
   
	return 0;
}

 
