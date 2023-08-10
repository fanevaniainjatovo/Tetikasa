
#include <stdio.h>

int main(int argc, char **argv)
{
    int mountainH[8]={3,7,6,5,9,4,8,2};
    
    for(int i=0;i<8;i++){
	    int o=0;
	    for(int j=0;j<8;j++){
		    if(mountainH[i]>=mountainH[j]){o++;}	
			
			}	
			printf("%d=%deme\n",mountainH[i],o);
		}
	
	return 0;
}

