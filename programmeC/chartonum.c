#include <stdio.h>
#include <string.h>
#include <math.h>
long double chartonum(char* mot);		
int main(){	
	char *mot="932";long double retour=0;
    retour=chartonum(mot);
    printf("%Lf",retour);
    return 0;
	}		
long double chartonum(char* mot){
		
    long double num=0;
	long double num1=0;
	int l=strlen(mot);
	int long1=0;	
		
		while(mot[long1]!='.' && mot[long1]!='\0' ){
			long1++;
			}
		
		for(int i=0;i<long1;i++){
		     num+=(mot[long1-1-i]-48)*pow(10,i);
			}
	    for(int i=l;i>long1+1;i--){
		     num1+=(mot[i-1]-48)*pow(10,l-i);
			}
    
    num+=num1*pow(10,long1+1-l);							

	return num;	
	}
