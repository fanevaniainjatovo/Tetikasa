
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* mandikakely(long long isa);
char * mandikafolo(long long isa);
char *mandikaotra(long long isa);
char* mandikaisa(long long isa);
char* mandika(long long isa);
long long *decomp(long long num);
int count(long long num);

int main(int argc, char **argv)
{ 
	long long isa=13235465767678098;
	char *soratra;
	printf("%lld\n",isa);
	soratra=mandika(isa);
	printf("%s",soratra);
	
	return 0;
}

char* mandika(long long isa){

		char **soratra=malloc(sizeof(char*)*(count(isa)+1));

		for(int i=0;i<count(isa)+1;i++){
			soratra[i]=malloc(10+10*i);
			  }
    
    if(isa%(long long)(pow(10,count(isa)))==0){
		   
		  soratra[count(isa)]=mandikaotra(isa);
		   		 
		 }
		 

	
	
	else{
	   if(count(isa)<2){
		    soratra[1]=mandikafolo(isa);
		   }
				
	   else{	
			soratra[count(isa)]=mandikakely(isa);
		   }
	
     }    
        
	
	return *(soratra+count(isa));
	
  }	
	
char* mandikaisa(long long elmt){
	
	char * soratra;
	
	char *aotra="aotra";
	char *iray="iray";
	char *roa="roa";
	char *telo="telo";
	char *efatra="efatra";
	char *dimy="dimy";
	char *enina="enina";
	char *fito="fito";
	char *valo="valo";
	char *sivy="sivy";
	char *folo="folo";
	
    char *roapolo="roapolo";
    char *telopolo="telopolo";
	char *efapolo="efapolo";
	char *dimampolo="dimampolo";
	char *enimpolo="enimpolo";
	char *fitopolo="fitopolo";
	char *valopolo="valopolo";
	char *sivifolo="sivifolo";
    char *zato="zato";

    char *roanjato="roanjato";
    char *telonjato="telonjato";
	char *efajato="efajato";
	char *dimanjato="dimanjato";
	char *eninjato="eninjato";
	char *fitonjato="fitonjato";
	char *valonjato="valonjato";
	char *sivinjato="sivinjato";
    char *arivo="arivo";
     
    char *alina="alina";
    char *hetsy="hetsy";
    char *tapitrisa="tapitrisa";
    char *lavitrisa="lavitrisa"; 
	
		switch(elmt){
			
			case 0:soratra=aotra;	
				break;
		
			case 1:soratra=iray;	
				break;	
		
			case 2:soratra=roa;		
				break;	
		
			case 3:soratra=telo; 	
				break;
		
			case 4:soratra=efatra;
				break;	 	
		
			case 5:soratra=dimy;	
				break;
		
			case 6:soratra=enina;
				break;
		
			case 7:soratra=fito;
				break;
		
			case 8:soratra=valo;
				break;
		
			case 9:soratra=sivy;	
				break;
		
			case 10:soratra=folo;
				break;
		 
			
			
			case 20:soratra=roapolo;
			    break;
			
		    case 30:soratra=telopolo;
				break;
				
			case 40:soratra=efapolo;
			    break;
			    
			case 50:soratra=dimampolo;    		
				break;
				
			case 60:soratra=enimpolo;
			    break;
			    
			case 70:soratra=fitopolo;
			    break;
			    
			case 80:soratra=valopolo;
			    break;
			    
			case 90:soratra=sivifolo;
			    break;
			    
			case 100:soratra=zato;
			    break;                	
			
			
			
			
			case 200:soratra=roanjato;
			    break;
			
		    case 300:soratra=telonjato;
				break;
				
			case 400:soratra=efajato;
			    break;
			    
			case 500:soratra=dimanjato;    		
				break;
				
			case 600:soratra=eninjato;
			    break;
			    
			case 700:soratra=fitonjato;
			    break;
			    
			case 800:soratra=valonjato;
			    break;
			    
			case 900:soratra=sivinjato;
			    break;
			    
			
			
			case 1000:soratra=arivo;
			    break;
			
			case 10000:soratra=alina;
			    break;
	
	        case 100000:soratra=hetsy;
			    break; 
		 
		    case 1000000:soratra=tapitrisa;
			    break;
		
			case 1000000000:soratra=lavitrisa;
			    break;
			    
 
			default :soratra="tsy mbola misy";    
		}
		
		
	return soratra;
	}

long long *decomp(long long num){
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
	        }
	    
	    
	return decomp;
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

char *mandikaotra(long long isa){
   
   char* soratra=malloc(100);
   long long *elmt=decomp(isa);
   
			if((elmt[0]/(long long)(pow(10,count(isa)))==1 && count(isa)==3) || count(isa)==0 || count(isa)==1 || count(isa)==2){
				soratra=mandikaisa(isa);
				}
			
			else{
				if(count(isa)<=6 || count(isa)%3==0){
				sprintf(soratra,"%s %s",mandikaisa(elmt[0]/(long long)(pow(10,count(isa)))),mandikaisa((long long)(pow(10,count(isa)))));
					}
				else{
					int i=0;
					long long tmp=elmt[0];
				    while((long long)(tmp)>(int)(pow(10,3))){tmp/=pow(10,3);i++;}
                 
			    tmp=elmt[0]/(int)(pow(10,3*i));
				sprintf(soratra,"%s %s",mandikaisa((long long)(tmp)),mandikaisa(elmt[0]/(long long)(tmp)));	
					
					}
				
				}
				
	return soratra;			
	}			

char * mandikafolo(long long isa){
	
	char* soratra=malloc(40);
	long long *elmt=decomp(isa);

		if(elmt[0]<100 && elmt[0]==10){
			
			if(elmt[1]==1){sprintf(soratra,"iraika ambin'ny %s",mandikaisa(elmt[0]));}
			else if(elmt[1]==0){sprintf(soratra,"%s",mandikaisa(elmt[0]));}
		    else{sprintf(soratra,"%s ambin'ny %s",mandikaisa(elmt[1]),mandikaisa(elmt[0]));} 
		     
			}
		
		else if(elmt[0]<100 && elmt[0]!=10 ){
		
			if(elmt[1]==1){sprintf(soratra,"iraika amby %s",mandikaisa(elmt[0]));}
			else if(elmt[1]==0){sprintf(soratra,"%s",mandikaisa(elmt[0]));}
			else{sprintf(soratra,"%s amby %s",mandikaisa(elmt[1]),mandikaisa(elmt[0]));}
		
			} 		
	
	return soratra;
	}
char * mandikakely(long long isa){
	  
	char *tohy[2]={"amby","sy"};
	long long *elmt=decomp(isa);
	char **soratra=malloc(sizeof(char*)*(count(isa)+1));
		
		for(int i=0;i<count(isa)+1;i++){
			soratra[i]=malloc(10+10*i);
			  }     
       
           int a=0;
		       int poszero=count(isa);
			if(elmt[count(isa)]+elmt[count(isa)-1]!=0){
				 sprintf(soratra[1],"%s",mandikafolo(elmt[count(isa)]+elmt[count(isa)-1]));
				}
				
	int i=2;	      
 while(i<=count(isa)){
			       
       if(i<6){
		   			   a=(i<=2)?0:1;
               while(elmt[poszero]==0){poszero--;}
              
			   if(i==count(isa)-poszero){
			   		if(elmt[count(isa)-i]!=0){
							sprintf(soratra[i],"%s",mandikaotra(elmt[count(isa)-i]));
						}
			
					else if(elmt[count(isa)-i]==0){
							strcpy(soratra[i],soratra[i-1]);
						}
		    
				  }
			    
			    else{
					if(elmt[count(isa)-i]!=0){
							sprintf(soratra[i],"%s %s %s",soratra[i-1],tohy[a],mandikaotra(elmt[count(isa)-i]));
						}
			
					else if(elmt[count(isa)-i]==0){
							strcpy(soratra[i],soratra[i-1]);
						}
					
					}	 
			
				i++;		
			   } 
			  
     

        
        else{   
			    	long long un=elmt[count(isa)-i]; 
					long long diz=elmt[count(isa)-i-1];
				    long long cen=elmt[count(isa)-i-2];
				    
                   	 
                un/=(long long)(pow(10,i));   	 
                diz/=(long long)(pow(10,i)); 
                cen/=(long long)(pow(10,i));
                 
             int opt=(i<7)?(i-1):(i-3);      
                
                if(un+diz!=0 && cen!=0){
				sprintf(soratra[i],"%s %s %s %s %s %s",soratra[opt],tohy[1],mandikafolo(un+diz),tohy[0],mandikaisa(cen),mandikaisa((long long)(pow(10,i)))); 
					
					}
					
				else if(un+diz==0 && cen!=0){
				sprintf(soratra[i],"%s %s %s %s",soratra[opt],tohy[1],mandikaisa(cen),mandikaisa((long long)(pow(10,i))));	
					
					}
					
				else if(un+diz!=0 && cen==0){
				sprintf(soratra[i],"%s %s %s %s",soratra[opt],tohy[1],mandikafolo(un+diz),mandikaisa((long long)(pow(10,i))));	
					
					} 
				i+=3;
			
			}
					
		 }	
		 		
	 					
       		   
 if(i<7){return soratra[count(isa)];}
 else{   return soratra[i-3];}
	
	}
