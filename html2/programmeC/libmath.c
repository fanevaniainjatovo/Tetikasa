
void css(char* chemin){
	
	FILE* css=fopen(chemin,"r");
    char style;
    
    printf("<style type=text/css>\n");
    printf("<!--\n");
  
    while(style!=EOF){style=fgetc(css);printf("%c",style);}
    
    printf("\n-->");
    printf("</style>\n");
	
	fclose(css);
	}


double f(double n){
	
	return log(n)-1;
	}

double derive(double a){
	
	return  (f(a+eps)-f(a))/eps ;
	
	}

int tangente(double a,double b){
	
	double s=a;
    int i=1;
    
	while(fabs(f(s))>eps ){
		
		if(f(b)*f(s)>0){printf("Tsy misy\n");break;}
		
		s=-f(s)/derive(s)+s;
		printf("<tr><td>%d</td><td>%lf</td></tr>",i,s);
		i++;
		}
		
	return i;
	
	}


int secante(double a,double b){
	
	double s=b;
	int i=1;
	while(f(s)>eps){
		
		if(f(a)*f(s)>0){printf("Tsy misy\n");break;}
		
		s=(fabs(f(a))*s+f(s)*a)/(fabs(f(a))+f(s));
		printf("<tr><td>%d</td><td>%lf</td></tr>",i,s);
		i++;
		
		}
	
	return i;
	
	}



int dicho(double a,double b){
	
    double s=0;
	int i=1;
	  while(fabs(a-b)>eps){
		
	    s=(a+b)/2;
	
		if(f(a)*f(s)<0){b=s;printf("<tr><td>%d</td><td>%lf</td></tr>",i,s);i++;}
	   	else if(f(s)*f(b)<0){a=s;printf("<tr><td>%d</td><td>%lf</td></tr>",i,s);i++;}
		else{printf("Tsy misy");break;} 
	   
		
		}
	
	return i;
	
	}
	

double inteTrap(double a, double b){
	
	double i;
	double ing=0;
	double inc=(a+b)/10;
	
	
	for(i=a;i<b-inc;i+=inc){

		
		ing+=(f(i)*(inc))+((f(i+inc)-f(i)))*(inc)/2;
		 
		
		}
	
	return ing; 
	
	}

