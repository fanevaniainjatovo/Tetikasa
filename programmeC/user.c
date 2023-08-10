/*
 * password.c
 * 
 * Copyright 2023 faneva <faneva@faneva-Aspire-V5-571P>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void shadow();
void passwd();
int main(int argc, char **argv)
{
    shadow();
    passwd();
	
	return 0;
	
}
void shadow(){
	char password[150];
    char commande[100];
    char nom[20];
    char passwd[200];
    char part[150];
    int stock=0;
    int i=0;
    char cmd[300];
    scanf("%s",nom);
    sprintf(commande,"cat ~/shadow");
    FILE* fp=popen(commande,"r");
	fgets(password,sizeof(password),fp);
     printf("%s\n",password);
	while(password[i]!=':'){
		i++;
		}
	stock=i;		
    
   // printf("%d\n",i);
    for(int j=stock;(j<=strlen(password));j++){part[j-stock]=password[j];}
    //for(int j=0;j<strlen(passwd);j++){printf("%c",passwd[j]);}
    //printf("%s\n",part);
    		
 //   for(int q=0;q<strlen(part);q++){(printf("%c",part[q]));}
	pclose(fp);
	strcpy(passwd,(strcat(nom,part)));
//	sprintf(cmd,"echo '%s' >> /etc/shadow",passwd);
//	system(cmd);
	//printf("%s\n",passwd);
	
	}
void passwd(){
	
	char commande[100];
	char PID[5000];
	sprintf(commande,"awk -F: '{print$3}' /etc/passwd >> passwd");
	FILE * fp=popen(commande,"r"); 
	fgets(PID,5000,fp);
	printf("%d",PID);
	
	}
