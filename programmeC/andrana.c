/*
 * andrana.c
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

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{   char commande[100]; 
   	FILE *fichier;
		sprintf(commande,"cat ~/vazoMisoma/usr/local/fichier/score2.txt");
		fichier = popen(commande, "r");
		char contain[100];
		fgets(contain, 100, fichier);
	//	int score= atoi(contain);
	    printf("%s",contain);
		pclose(fichier);	
	return 0;
}

