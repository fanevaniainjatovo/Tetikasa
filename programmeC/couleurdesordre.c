#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        srand(time(NULL));
		
		char valinkorontana[100];
		char tenaizy[]="Fy Rasolofoniaina";
		long len=strlen(tenaizy);
		
		char *comp=malloc(len+1);
		
		strcpy(comp,tenaizy);
	
		char tmp;
		
		int numRand=8;
		int numRand2=9;
        
        ambony: 
		
		for(int i=0;i<(57+numRand);i++){
			
			numRand=(int)(((float)(len)*rand())/(RAND_MAX +1.0));
			numRand2=(int)(((float)(len)*rand())/(RAND_MAX+1.0));
		while(numRand==numRand2){numRand2=(int)(((float)(len)*rand())/(RAND_MAX+1.0));}
		    
		   
			tmp=tenaizy[numRand];
			tenaizy[numRand]=tenaizy[numRand2];
			tenaizy[numRand2]=tmp;
			
		    }
		
		int etg=strcmp(tenaizy,comp);	
        if(etg==0){goto ambony;}
        printf("%s\n",comp);
        printf("\033[34m~\033[0m");
		for(int i=0;i<len;i++){
			if(tenaizy[i]!='\n'){
			printf("%c\033[34m~\033[0m",tenaizy[i]);}}
			
			
		         
		printf("\n\033[33mRéponse\033[0m=>");
		fgets(valinkorontana,100,stdin);
	
		
		   for(int i=0;i<strlen(tenaizy);i++){
			   
			   if(i<strlen(valinkorontana) && valinkorontana[i]!='\n'){
			   
			   if(valinkorontana[i]==comp[i]){
				   if(valinkorontana[i]!=' '){printf("\033[32m%c\033[0m",valinkorontana[i]);}
				   else{printf("\033[42m%c\033[0m",valinkorontana[i]);}
				   }
			   else if(valinkorontana[i]!=comp[i]){
				   if(valinkorontana[i]!=' '){printf("\033[31m%c\033[0m",valinkorontana[i]);}
				   else{printf("\033[41m%c\033[0m",valinkorontana[i]);}
					   }
			   
			      }
			     } 
			     
			   if(strlen(tenaizy)>strlen(valinkorontana)){
				   printf("\033[31m*\033[0m");
				   }
			  
			   else if(strlen(tenaizy)<strlen(valinkorontana)){
				   
				   for(int i=strlen(tenaizy);i<strlen(valinkorontana);i++){
				    if(valinkorontana[i]!='\n'){
						printf("\033[9;31;5m%c\033[0m",valinkorontana[i]);
						}
			           }
				   } 
				
           
                
	
	return 0;
}

