#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long double chartonum(char *mot);
char ** datetohms(char *date);
long double* jourtohms(long double jour);
char *intochar(int num);
//char *floatochar(float num);

int main(int argc, char **argv){
	
	char *date="16/7/2021";
	printf("%s\n",date);
    datetohms(date);	
	return 0;
	}

char ** datetohms(char *date){	
	char ** hms;
	int slash=0;
	int len[2]={0};
	int l=strlen(date);
		
		hms=malloc(6*sizeof(char*));	
            
        for(int i=0;i<l;i++){
			if(date[i]=='/'){len[slash]=i;slash++;}
		   }
		
			*(hms)=malloc(len[0]-1);
			*(hms+1)=malloc(len[1]-len[0]-1);
			*(hms+2)=malloc(l-len[1]-1);
		    
			for(int j=0;j<len[0];j++){		hms[0][j]=date[j];		}		
		
			for(int j=len[0]+1;j<len[1];j++){		hms[1][j-len[0]-1]=date[j];		}
		    
		    for(int j=len[1]+1;j<l;j++){		hms[2][j-len[1]-1]=date[j];	     } 
		
				   
            long double *numHms=malloc(sizeof(long double)*3);            

   			for(int i=0;i<3;i++){numHms[i]=chartonum(hms[i]);}
       
              
             ///annee et mois 
                numHms[1]+=(numHms[2]-(int)(numHms[2]))*12;    
                numHms[2]=(int)(numHms[1])/12+(int)(numHms[2]);
			    numHms[1]=(int)(numHms[1])%12+numHms[1]-(int)(numHms[1]);   
			   
				if((int)(numHms[1])%12==0){
					numHms[1]=12+numHms[1]-(int)(numHms[1]);
					numHms[2]--;
					}            
                printf("%Lf\n%Lf\n",numHms[1],numHms[2]); 
            
            ///jour, peut etre mois et peut etre annee
            
          if(((int)(numHms[1])%2==1 && numHms[1]<=7) || ((int)(numHms[1])%2==0 && numHms[1]>7)){
		      if((int)(numHms[2])%4!=0 && (int)(numHms[1])==2){ numHms[0]+=(numHms[1]-(int)(numHms[1]))*28;}
		      else if((int)(numHms[2])%4==0 && (int)(numHms[1])==2){ numHms[0]+=(numHms[1]-(int)(numHms[1]))*29;}
		      else if((int)(numHms[1])!=2){ numHms[0]+=(numHms[1]-(int)(numHms[1]))*31;}
			   }
			   
		  else if(((int)(numHms[1])%2==0 && numHms[1]<=7) || ((int)(numHms[1])%2==1 && numHms[1]>7)){
		        numHms[0]+=(numHms[1]-(int)(numHms[1]))*30;	 
			   }   
			       printf("%Lf\n",numHms[0]);
			 	  while((int)(numHms[0])>31){	
				   if((int)(numHms[1])%2==1 && (int)(numHms[1])!=1){
					   if(numHms[1]<=7){numHms[0]-=30;}
					   else if(numHms[1]>7){numHms[0]-=31;}
					   numHms[1]++;
					   if((int)(numHms[1])>12){
						   numHms[1]=(int)(numHms[1])%12+numHms[1]-(int)(numHms[1]);
						   numHms[2]++;}
					  	   
						   }
				   
				   else if((int)(numHms[1])%2==0){
					   if(numHms[1]>7){numHms[0]-=30;}
					   else if(numHms[1]<=7){numHms[0]-=31;}
					   numHms[1]++;
					   if((int)(numHms[1])>12){
						   numHms[1]=(int)(numHms[1])%12+numHms[1]-(int)(numHms[1]);
						   numHms[2]++;}
						
						   }
				   
				   else if((int)(numHms[1])==1 && (int)(numHms[2])%4!=0){
					   numHms[0]-=28;numHms[1]++;
					   if((int)(numHms[1])>12){
						   numHms[1]=(int)(numHms[1])%12+numHms[1]-(int)(numHms[1]);
						   numHms[2]++;}
						  
						   }
					   
				   else if((int)(numHms[1])==1 && (int)(numHms[2])%4==0){
					   numHms[0]-=29;numHms[1]++;
					   if((int)(numHms[1])>12){
						   numHms[1]=(int)(numHms[1])%12+numHms[1]-(int)(numHms[1]);
						   numHms[2]++;}
						   
						   }	   
					  
					   } 
				  
				  if((int)(numHms[1])%2==0 && (int)(numHms[1])!=2 && (int)(numHms[0])>30){
					  numHms[0]-=30;numHms[1]++;
					  if((int)(numHms[1])>12){
						   numHms[1]=(int)(numHms[1])%12+numHms[1]-(int)(numHms[1]);
						   numHms[2]++;}
						   
						   }
					  
				  
				  if((int)(numHms[1])==2 && (int)(numHms[0])>28){
			           if((int)(numHms[2])%4!=0){numHms[0]-=28;      numHms[1]++;}
					   else{
						   if(numHms[0]!=29){numHms[0]-=29;      numHms[1]++;}
						   }
					      
					     }
					         
					  numHms[1]=(int)(numHms[1]);
					      			 	
			    long double *smo=malloc(sizeof(long double)*3); 	
			    smo=jourtohms(numHms[0]-(int)(numHms[0]));
			    numHms[0]=(int)(numHms[0]);
			    for(int i=0;i<3;i++){hms[i]=intochar(numHms[i]);}
			    for(int i=3;i<6;i++){hms[i]=intochar(smo[i-3]);}
		
	            for(int i=0;i<3;i++){printf("%s",hms[i]);if(i!=2){printf("/");}}  
	            printf(" à ");
	            for(int i=3;i<6;i++){printf("%s",hms[i]);if(i!=5){printf(":");}} 
	return hms;	       
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
	

long double* jourtohms(long double jour){
	   long double* hms=malloc(3*sizeof(long double));
	   int sec=jour*86400;
	   long double sectmp=jour*86400;
			hms[0]=sec/3600;   
    
       int min=sec%3600;
			hms[1]=min/60;
			
			hms[2]=sectmp-hms[0]*3600-hms[1]*60;
			
			
	return hms;
	}

/*char **floatochar(float num){
	

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
	     *(mot+2)=intochar(diff);
	   
	
	
	 return mot;
	}*/
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
