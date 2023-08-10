#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char *intochar(int num);
char *floatochar(float num);
char* datetovirgule(char* date);
long double chartonum(char* jour); 

int main(int argc, char **argv)
{
	char* date="23/6/2023	3:56:09";
	
	char* datevirgule=datetovirgule(date);
	
	printf("%s\n",datevirgule);
	return 0;
}

char* datetovirgule(char* date){
	
	int deuxpoint[2]={0};
	int deu=0;
	int slash=0;
	int space=0;
	char* reste=malloc(8);
	char* jour=malloc(3);
	char *heure=malloc(3);
	char *minute=malloc(3);
	char *seconde=malloc(3);
	
	while(date[slash]!='/'){
        slash++;
     }
	
	for(int i=0;i<strlen(date);i++){
		
	    if(date[i]=='	'){space=i;}
		else if(date[i]==':'){deuxpoint[deu]=i;deu++;}
		
		}

    for(int i=0;i<strlen(date);i++){
		
	    if(i<slash){jour[i]=date[i];}
	    else if(i>=slash && i<space){reste[i-slash]=date[i];}
		else if(i>space && i<deuxpoint[0]){heure[i+2-deuxpoint[0]]=date[i];}
		else if(i>deuxpoint[0] && i<deuxpoint[1]){minute[i+2-deuxpoint[1]]=date[i];}
		else if(i>deuxpoint[1]){seconde[i-deuxpoint[1]-1]=date[i];}
		
		} 

   long double numHeure=chartonum(heure);
   long double numMinute=chartonum(minute);
   long double numSeconde=chartonum(seconde);
    	
    long double numJour=chartonum(jour);	
    long double jourvirgule=numJour+(numSeconde/86400+numMinute/1440+numHeure/24);
    
    	
	char* datevirgule=malloc(strlen(date));  
	sprintf(datevirgule,"%s%s",floatochar(jourvirgule),reste);
	
	
	return  datevirgule;
	
	
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

char *floatochar(float num){
	
	float numint=num-(int)(num);
	long long i=1;
	int dizvirg=0;	
	
		while((numint)*i-(int)(numint*i)!=0 && ((numint)-(int)(numint))*i!=0){		
	            
			    
			    dizvirg++;
		        i*=10;

		         
		     }
		   	
	char **mot=malloc(3*sizeof(char*));
        *mot=intochar((int)(num));	  
	   
	   int zerovirg=0;
			i=1;
	   while((int)(numint*i)==0 && num!=(int)(num)){zerovirg++;i*=10;}
	   
	    
	    *(mot+1)=malloc(zerovirg);
	      mot[1][0]='.';
	   for(int i=1;i<zerovirg;i++){
			mot[1][i]='0';
		   }
	    
	int diff=(numint)*pow(10,dizvirg);	
	     *(mot+2)=intochar(diff);
	   
	  char* soratra=malloc(strlen(mot[0])+strlen(mot[1])+strlen(mot[2]));
	   
	  sprintf(soratra,"%s%s%s",mot[0],mot[1],mot[2]);
	  
	
	return soratra;
    }

char *intochar(int num){
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
