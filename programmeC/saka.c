
#include <faneva.h>

int main(int argc, char **argv)
{
	char cmd1[30];
	char saka[100];
	
	sprintf(cmd1,"cat ~/saka");
		
		
			FILE *fd=popen(cmd1,"r");
			fgets(saka,100,fd);
			
		for(int i=0;i<strlen(saka);i++){	
			printf("%c",toupper(saka[i]));
		    }	  
			
	return 0;
}

