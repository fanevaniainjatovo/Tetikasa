#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	for(int i=130;i<200;i++){
		printf("\033[%dmandrana\033[0m\n%d\n",i,i);
		sleep(2);
		system("clear");
		}
		
			
	
	return 0;
}

