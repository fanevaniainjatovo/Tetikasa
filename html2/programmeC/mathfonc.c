

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-9
#include "libmath.c"


int main(int argc, char **argv)
{
    
    printf("Content-type:text/html\n\n");
    
    double a=1,b=78;
    int i=0;
    char* method=getenv("QUERY_STRING");
    char x[2],tsy[3][30],ba[12],bb[12];
    
    sscanf(method,"%[^=]=%[^&]&%[^=]=%[^&]&%[^=]=%[^\n]",tsy[1],ba,tsy[2],bb,tsy[0],x);
    
    sscanf(ba,"%lf",&a);
    sscanf(bb,"%lf",&b); 
    
    printf("<body>");
    
    printf("<h1>Fonction log(x)-1 </h1>");
        
    css("/home/faneva/html2/css/math.css");
    
    printf("<center>");
    printf("<form action=\"./mathfonc.cgi\" method=\"get\">");
    printf("<input placeholder=\"borne1\" type=\"number\" step=\"0.01\" name=\"borne1\">");
    printf("<input placeholder=\"borne2\" type=\"number\" step=\"0.01\" name=\"borne2\">");
    printf("</br><button type=\"submit\" name=\"method\" value=\"d\">Methode de dichotomie</button>");
    printf("<button type=\"submit\" name=\"method\" value=\"c\">Methode de Descartes</button>");
    printf("<button type=\"submit\" name=\"method\" value=\"n\">Methode de Newton</button>");
    printf("<button type=\"submit\" name=\"method\" value=\"i\">Calcul d` Integrale</button>");
    printf("</form>");
    printf("</center>");
    
    printf("<div class=\"main\">");
    
    printf("<center>");  
    if(strcmp(x,"d")==0){
   
    printf("<table border>");
    i=dicho(a,b);
    printf("<h2>%d iterations</h2>",i-1);
    printf("</table>");
   
       }
  
    else if(strcmp(x,"c")==0){
     
    printf("<table border>");
    i=secante(a,b); 
    printf("<h2>%d iterations</h2>",i-1);
    printf("</table>");
     	
	   }
    
    else if(strcmp(x,"n")==0){
     	
	printf("<table border>");
    i=tangente(a,b); 
    printf("<h2>%d iterations</h2>",i-1);
    printf("</table>");
    
       }
	
	else if(strcmp(x,"i")==0){
		
	printf("<h2>%lf</h2>",inteTrap(a,b));
		
		}
		
	
    printf("</center></div>");
	printf("</body>");
	
	return 0;
}

