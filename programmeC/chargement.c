#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char **argv)
{   for(int j=0;j<10;j++){
		for(int i=0;i<j;i++){printf(" ");}
			printf("\033[35mV\033[0m");
		for(int i=j;i<10;i++){printf(" ");}
			printf("\033[35ma\033[0m");
		for(int i=0;i<j;i++){printf(" ");}
			printf("\033[35mz\033[0m");
		for(int i=j;i<10;i++){printf(" ");}
			printf("\033[35mo\033[0m");
			printf("\t");
						
		for(int i=0;i<j;i++){printf(" ");}	
		    printf("\033[35mM\033[0m");
		for(int i=j;i<10;i++){printf(" ");}	
		    printf("\033[35mi\033[0m");
		for(int i=0;i<j;i++){printf(" ");}	
		    printf("\033[35ms\033[0m");
		for(int i=j;i<10;i++){printf(" ");}	
		    printf("\033[35mo\033[0m");
		for(int i=0;i<j;i++){printf(" ");}	
		    printf("\033[35mm\033[0m");
		for(int i=j;i<10;i++){printf(" ");}	
		    printf("\033[35ma\033[0m\n");
	                    
		    usleep(500000);
			system("clear");
	}		
	
	return 0;
}

