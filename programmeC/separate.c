
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{   
	char* mot="895.67";
	char ** result=malloc(2*sizeof(char*));;
	int long1=0;
	int l=strlen(mot);
		
		while(mot[long1]!='.' && mot[long1]!='\0' ){
			long1++;
			}
			
	        *result=malloc(long1);
	        *(result+1)=malloc(l-long1-1); 
	         
	    for(int i=0;i<long1;i++){result[0][i]=mot[i];}   
	    for(int i=long1+1;i<l;i++){result[1][i-long1-1]=mot[i];}
	    
	printf("%s\n",result[0]);
	printf("%s",result[1]);

	return 0;
}

