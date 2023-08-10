
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char *numtochar(int num);
int main(int argc, char **argv){
	
	float num=905;
	float numint=num-(int)(num);
	long long i=1;
	int dizvirg=0;	
	
		while((numint)*i-(int)(numint*i)!=0 && ((numint)-(int)(numint))*i!=0){		
	            
			    
			    dizvirg++;
		        i*=10;

		         
		     }
		   	
	char **mot=malloc(3*sizeof(char*));
        *mot=numtochar((int)(num));	  
	   
	   int zerovirg=0;
			i=1;
	   while((int)(numint*i)==0 && num!=(int)(num)){zerovirg++;i*=10;}
	   
	    
	    *(mot+1)=malloc(zerovirg);
	      mot[1][0]='.';
	   for(int i=1;i<zerovirg;i++){
			mot[1][i]='0';
		   }
	    
	int diff=(numint)*pow(10,dizvirg);	
	     *(mot+2)=numtochar(diff);
	   
	  char* soratra=malloc(strlen(mot[0])+strlen(mot[1])+strlen(mot[2]));
	   
	  sprintf(soratra,"%s%s%s",mot[0],mot[1],mot[2]);
	  
	  printf("%s",soratra);
	return 0;
    }

char *numtochar(int num){
	int i=1;
	int diz=0;
	
	while((num/i)>=10){		
		i*=10;
		diz++;
		}
	char *mot=malloc(diz+1);
	
	for(int i=0;i<diz+1;i++){
			if(i==0){mot[i]=num/pow(10,diz-i)+48;}
			else{mot[i]=(num%(int)(pow(10,diz+1-i)))/pow(10,diz-i)+48;}
	
	   }
	
	return mot;
   }
