#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char **argv)
{   long long num=746; 
    long long i=1;
	int diz=0;
	
	while((num/i)>=10){		
		i*=10;
		diz++;
	    }
	long long *decomp=malloc(sizeof(long long)*(diz+1));
	   
	   for(int i=0;i<diz+1;i++){
			if(i==0){decomp[i]=((num/(long long)(pow(10,diz-i)))*(long long)(pow(10,diz-i)));}
			else{decomp[i]=((num%(long long)(pow(10,diz+1-i)))/(long long)(pow(10,diz-i)))*(long long)(pow(10,diz-i));}
	        printf("%lld\n",decomp[i]);
	        }
	         	
	return 0;
}

