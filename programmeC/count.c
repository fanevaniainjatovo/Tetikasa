
#include <stdio.h>

int count(long long num);

int main(int argc, char **argv)
{
    int a=99148;
    printf("%d\n",count(a)); 	
	printf("%s",argv[5]);
	
	return 0;
	
}


int count(long long num){
	long long i=1;
	int diz=0;
	
	while((num/i)>=10){		
		i*=10;
		diz++;
	
	     }
	
	return diz;
	 }
