
#include "Cercle.h"
#include <math.h>

using namespace std;
	
int main(int argc, char **argv)
{	
	srand(time(NULL));
	
	int n=random(7,2);
	Cercle c[n];
    Point a[n];
    int rayon[n];
    string couleur[n];
    int x[n];
    int y[n];
      
	cout<<"Voici les cercles avec leurs positions initiales,leurs couleurs et leurs rayons respectifs:\n\n";
		
    for(int i=0;i<n;i++){
		
		c[i]=Cercle();
		a[i]=Point();
			
		c[i].setCentre();
		c[i].setCouleur();
		c[i].setRayon();
		
		a[i]=c[i].getCentre();
			x[i]=a[i].getX();
		    y[i]=a[i].getY();
		couleur[i]=c[i].getCouleur();
		rayon[i]=c[i].getRayon();
		
		//Les Cercles et leurs Attributs en position initiale
		
		cout<<"\tCercle["<<i<<"] << x="<<x[i]<<" y="<<y[i]<<" / couleur="<<couleur[i]<<" / rayon="<<rayon[i]<<">>"<<endl;
	  
		}
	cout<<endl<<endl;

ambony:
	
	//les cercles qui se chevauchent deux a deux
	
	cout << "Voici les cercles qui se chevauchent pris deux par deux:\n\n";
		
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(j!=i){
				if(sqrt((y[i]-y[j])*(y[i]-y[j])+(x[i]-x[j])*(x[i]-x[j]))<rayon[i]+rayon[j]){
					cout<<"\tCercle["<<i<<"] et "<<"Cercle["<<j<<"]"<<endl;
					}
			   }
		   }
	   }
	 
	cout<<endl<<endl<<"Ceux qui suivent sont les deplacements des cercles pour qu'ils ne se chevauchent plus:\n\n";  
	 //Deplacement 
	for(int i=0;i<n;i++){
		
	a[i]=c[i].getCentre();	
		
		x[i]=a[i].getX();
		y[i]=a[i].getY();

		
		for(int j=i;j<n;j++){
			if(j!=i){
				while(sqrt((y[i]-y[j])*(y[i]-y[j])+(x[i]-x[j])*(x[i]-x[j]))<rayon[i]+rayon[j]){
			
					c[i].deplace(x[i],y[i]); 
					
					cout<<"\tCercle["<<i<<"] -> x="<<x[i]<<" / y="<<y[i]<<endl;
					sleep(1);
					
						(x[i]>=x[j])?x[i]++:x[i]--;
						(y[i]>=y[j])?y[i]++:y[i]--;
	                
	               }
	           }
	       }
	       cout<<endl;
	    }
	  
	     cout<<endl<<endl<<"Ainsi voici le resultat:\n\n";
	 //Positions finales des Cercles
	     
	 for(int i=0;i<n;i++){
		 
		cout<<"\tCercle["<<i<<"] << x="<<x[i]<<" y="<<y[i]<<" / couleur="<<couleur[i]<<" / rayon="<<rayon[i]<<">>"<<endl; 
		 
		 }
	     
	     cout << endl;
		 
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(j!=i){
				if(sqrt((y[i]-y[j])*(y[i]-y[j])+(x[i]-x[j])*(x[i]-x[j]))<rayon[i]+rayon[j]){
					goto ambony;
					}
			   }
		   }
	   }
	   
	             
	return 0;
}

