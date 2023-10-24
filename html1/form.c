
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "andro.c"
#include "css.c"


int main(int argc, char **argv)
{   
    char op[30];
    char co[30];
       
    testconnex(op);
    
    if(atoi(op)==0){printf("Location: http://www.cv.fr/cgi-bin/login.cgi\n\n");}
    
    
    else{
        
    printf("Content-type:text/html\n\n");
    
    css("/home/faneva/html1/css/auth.css"); 
    
    printf("<body>");  
    printf("<center>");
    
    deconnex(co);
    auth(); 
    
    }
   
    	
	return 0;
}

