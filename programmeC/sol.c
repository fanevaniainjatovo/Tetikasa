
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
		     for(int j=0;j<34;j++){
			    for(int i=0;i<j-2;i++){printf(" ");}	
			    printf("\033[32;5mo\n");
			    
			    for(int i=j-4;i<58;i++){printf(" ");}
			    printf("o   o\n");
			    
			    for(int i=0;i<j-3;i++){printf(" ");}
			    printf("ooo\n");
			
			    for(int i=j-3;i<60;i++){printf(" ");}
			    printf("oo\n");
			  
			    for(int i=0;i<j-5;i++){printf(" ");}
			    printf("o  o\n");
			  
			    for(int i=j-7;i<52;i++){printf(" ");}
			    printf("o    o\n");
			  
			    for(int i=0;i<j-9;i++){printf(" ");}
			    printf("o      ooo\n");
			 
			    for(int i=j-10;i<46;i++){printf(" ");}
			    printf("o     o o  o\n");

			    for(int i=0;i<j-9;i++){printf(" ");}
			    printf("o   o  oo  o\n");
			
			    for(int i=j-8;i<50;i++){printf(" ");}
			    printf("o   ooo  o\n");
			
			    for(int i=0;i<j-6;i++){printf(" ");}
			    printf("o  oo o\n");
		
			    for(int i=j-3;i<60;i++){printf(" ");}
			    printf("oo\n");
		
			    for(int i=0;i<j-2;i++){printf(" ");}	
			    printf("o\n");
	
			    for(int i=j-6;i<55;i++){printf(" ");}	
			    printf("oo  o\n");
			
			    for(int i=0;i<j-6;i++){printf(" ");}	
			    printf("o  o o\n");	
	
			    for(int i=j-5;i<57;i++){printf(" ");}	
			    printf("o o\033[0m\n");
			    
			   if(j!=33){usleep(30000);
			   
			    system("clear");
			    
			    }  
			  }
		 sleep(3);	  	
		 system("clear");	  
	char vazo[]="VazoMisoma";
	
			  for(int j=0;j<10;j++){ 
				  printf("\n");
				 for(int k=0;k<strlen(vazo);k++){
					if(k%2==0){
						for(int i=0;i<j;i++){printf(" ");}
						printf("\033[32m%c\033[0m",vazo[k]);
					    }
					    
					else{
						for(int i=j;i<10;i++){printf(" ");}
						printf("\033[31m%c\033[0m",vazo[k]);
						}
					  	
					}
					//printf("\n");	
					usleep(500000);
					system("clear");
			            
				}
	      system("clear");   
		         
	return 0;
}

