
#include <stdio.h>
#include <math.h>
#define PI 3.141592654
#include <time.h>

int main(int argc, char **argv)

{
    printf("\t\tTABLEAU TRIGONOMETRIQUE\n");
    
    FILE* f=fopen("/home/faneva/table_trigo.csv","w+");
    
    fprintf(f,"DEGRE,RADIAN,SINUS,COSINUS,TANGENTE,COTANGENTE\n");
    
    double y=1;
    for(double x=0;x<=360;x++){
		y=(x*PI)/180;
		fprintf(f,"%lf,%lf,%lf,%lf,%lf,%lf\n",x,y,sin(y),cos(y),sin(y)/cos(y),cos(y)/sin(y));      
       }
    
    for(int i=0;i<=126;i++){printf("%d\t%c\n",i,i);}
    
    printf("FAIT");
    
    fclose(f);	
	return 0;
}

