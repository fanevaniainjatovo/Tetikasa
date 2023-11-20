
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void virtualhost(char* servername){
	
	FILE* f;
	FILE* f1;
	char cmd[200],fic[1000],www[100];
	
	f=fopen("/etc/apache2/sites-available/000-default.conf","r");
	
	if(strcmp(servername,"NEW")){
	
		sprintf(cmd,"/etc/apache2/sites-available/%s.conf",servername);	
		f1=fopen(cmd,"a");
	
			while(fgets(fic,1000,f)){
			
				if(strstr(fic,"ServerName www.faneva.com")){
					sprintf(www,"\tServerName www.%s.com\n",servername);
					fprintf(f1,"%s",www);
					}
			
				else if(strstr(fic,"DocumentRoot /home/faneva/")){
					sprintf(www,"\tDocumentRoot /home/faneva/%s/\n",servername);
					fprintf(f1,"%s",www);
					}
	        
				else if(strstr(fic,"ScriptAlias")){
					sprintf(www,"\tScriptAlias /cgi-bin/ /home/faneva/%s/cgi-bin/\n",servername);
					fprintf(f1,"%s",www);
					}		
			
				else if(strstr(fic,"<Directory")){
					if(strstr(fic,"cgi-bin")){
						sprintf(www,"\t<Directory /home/faneva/%s/cgi-bin/>\n",servername);
						fprintf(f1,"%s",www);
						}
					else{
						sprintf(www,"\t<Directory /home/faneva/%s/>\n",servername);
						fprintf(f1,"%s",www);
						}  
					}
			
				else{fprintf(f1,"%s",fic);}
			
	
			}
	//	printf("<h1>L'ajout de votre nouvel hote virtuel www.%s.com est confirme</h1>",servername);
		fclose(f1);
	    }
	
	fclose(f);
	
	}

void apacheconf(char* servername){
	
	FILE *f,*f1;
	char fic[255];
	
	if(strcmp(servername,"NEW")){
	
		f=fopen("/etc/apache2/apache2.conf","r");	
		f1=fopen("/etc/apache2/apache2.test","w");	
		fclose(f1);
		
		f1=fopen("/etc/apache2/apache2.test","a");
		
		while(fgets(fic,255,f)){
			if(strstr(fic,"<Directory /var/www")){
				fprintf(f1,"<Directory /home/faneva/%s/>\n",servername);
				fprintf(f1,"\tOptions Indexes FollowSymLinks\n");
				fprintf(f1,"\tAllowOverride None\n");
				fprintf(f1,"\tRequire all granted\n");
				fprintf(f1,"</Directory>\n\n");
				fprintf(f1,"%s",fic);
				}
		
			else{
				fprintf(f1,"%s",fic);
				}
		
			}
			
		fclose(f);
		fclose(f1);
		
		
		f=fopen("/etc/apache2/apache2.conf","w");	
		fclose(f);
		
		f=fopen("/etc/apache2/apache2.conf","a");	
		f1=fopen("/etc/apache2/apache2.test","r");	
		
		while(fgets(fic,255,f1)){
	        		
			fprintf(f,"%s",fic);
			
			}
		
	//	printf("<h1>La configuration de apache2 est termine</h1>");	
		fclose(f);
		fclose(f1);
	 }
 
 }


void repertoire(char* servername){
	
	int a,b;
	char rep[30];
	char srep[50];
	
	sprintf(rep,"/home/faneva/%s",servername);
	sprintf(srep,"%s/cgi-bin/",rep);
	
	if(strcmp(servername,"NEW")){
	
		a=mkdir(rep,0755);
		b=mkdir(srep,0755);
/*		
		if(a==0){printf("<h1>Le repertoire /home/faneva/%s/ a ete cree</h1>",servername);}
		else{printf("<h1>erreur lors de la creation du repertoire /home/faneva/%s/.Il existe peut-etre deja</h1>",servername);}
	
		if(b==0){printf("<h1>Le repertoire /home/faneva/%s/cgi-bin a ete cree</h1>",servername);}
		else{printf("<h1>erreur lors de la creation du repertoire /home/faneva/%s/cgi-bin.Il existe peut-etre deja</h1>",servername);}
	*/
      }
	
   }

void host(char* servername){
	
	FILE *f,*f1;
	char fic[255];
	
	if(strcmp(servername,"NEW")){
	
		f=fopen("/etc/hosts","r");	
		f1=fopen("/etc/hosts1","w");	
		fclose(f1);
		
		f1=fopen("/etc/hosts1","a");
		while(fgets(fic,255,f)){
	    	
			if(strstr(fic,"www.cv.fr")){
				fprintf(f1,"%s",fic);
				fprintf(f1,"127.0.0.1\twww.%s.com\n",servername);
				}
		
			else{
				fprintf(f1,"%s",fic);
				}
		
			}
			
		fclose(f);
		fclose(f1);
		
		
		f=fopen("/etc/hosts","w");	
		fclose(f);
		
		
		f=fopen("/etc/hosts","a");	
		f1=fopen("/etc/hosts1","r");	
		
		while(fgets(fic,255,f1)){
			
			fprintf(f,"%s",fic);
			
			}
		
//		printf("<h1>Le DNS est configure</h1>");	
		fclose(f);
		fclose(f1);
	 }
	
	}
	
void enable(){
	
	char cmd[200];
	char* servername=malloc(20);
	
	FILE* name=fopen("/home/faneva/fic","r");
	
	fgets(servername,20,name);

	sprintf(cmd,"sudo a2ensite %s",servername);
    
    printf("Content-type: text/html\n\n");
    
    popen(cmd,"w");
    
    //refreshing of the site
    
    printf("<meta http-equiv=\"refresh\" content='1;url=http://www.creervotresite.com/cgi-bin/creersite.cgi?enable=1'");	
    popen("sudo systemctl reload apache2","w");	
	
	fclose(name);
	}

void disable(){
	
	char cmd[200],servername[20];
	
	FILE* name=fopen("/home/faneva/fic","r");
	
	fgets(servername,20,name);
	sprintf(cmd,"sudo a2dissite %s",servername);
	
	popen(cmd,"w");
	
	//refreshing of the site
	
	printf("<meta http-equiv=\"refresh\" content='1;url=http://www.creervotresite.com/cgi-bin/creersite.cgi?disable=1'");
	popen("sudo systemctl reload apache2","w");
	
	fclose(name);
	}

int main(int argc, char **argv)
{
	
	char servername[30],tsy[20],hafa[20];
	char* entry=malloc(40);
	FILE* name;
	
	entry=getenv("QUERY_STRING");
	strcpy(servername,"NEW");
	sscanf(entry,"%[^=]=%[^\n]",tsy,servername);

	
	if(strcmp(tsy,"enable")==0){enable();printf("<h1>Le site est active</h1>");}	
	else if(strcmp(tsy,"disable")==0){disable();printf("<h1>Le site est desactive</h1>");}
	else if(strcmp(servername,"NEW")==0){printf("Location: http://www.creervotresite.com/creersite.html\n\n");}
	else{
		name=fopen("/home/faneva/fic","w");
		fprintf(name,"%s\n",servername);
		fclose(name);
		repertoire(servername);
		virtualhost(servername);
		host(servername);
		apacheconf(servername);
		printf("Location: http://www.creervotresite.com/activation.html\n\n");
		}
		
	return 0;
}

