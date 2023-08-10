
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *popo="affg";
	char *pipi[6];
	int q=815;
	
	for(int i=0;i<6;i++){
	pipi[i]=malloc(strlen(popo)+5);
		}
	
	for(int i=0;i<6;i++){
	if(i>=1){sprintf(pipi[i],"%s %d %s",pipi[i-1],q,popo);}
	else{sprintf(pipi[i],"%s %d",popo,q);}
	printf("%s\n",pipi[i]);
		}
	
	
	return 0;
}

