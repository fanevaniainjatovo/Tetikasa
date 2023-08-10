
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char *genermdp(int n);
int main(int argc, char **argv){
	
	while(1){
	printf("%s\n",genermdp(10));
	sleep(1);
    }
	
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
