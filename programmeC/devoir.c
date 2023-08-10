


#include <stdio.h>
#include <math.h>

float f(float var);
int main(int argc, char **argv)
{
	printf("\t\tTABLEAU DE FONCTION\n");
	
	
    float a=0;
    float b=0;
    float n=0;
    
    printf("Entrez les bornes:\nBorne inferieur=");
    scanf("%f",&a);
    printf("Borne superieur=");scanf("%f",&b); 
    printf("Nombre de termes=");scanf("%f",&n);
    
    float min=(a>=b)?b:a;
    float max=(a<=b)?b:a;
    float ampl=(max-min)/n;
    
    
    FILE* file=fopen("/home/faneva/faneva.csv","w+");
    
    for(float i=min;i<=max;i+=ampl){
       fprintf(file,"%f,%f\n",i,f(i));
        }
    
    fclose(file);
      	
	return 0;
}

float f(float var){
	
	float carre=pow(var,2);
	
	return carre;
	}

