
#include "Point.h"
#include <string>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;
class Cercle{
	
	private:
		Point centre=Point();
		int rayon;
		string couleur;
	
	public:
		Cercle(){}
		~Cercle(){}
		
		Point getCentre();
		void setCentre();
		
		int getRayon();
		void setRayon();
		
		string getCouleur();
		void setCouleur();	
		
		void deplace(int x,int y);
	};
	
int random(int max,int min){

	return rand()%(max-min+1)+min;	
	
	}

void Cercle::deplace(int x,int y){
	centre.setX(x);
	centre.setY(y);
	}
	
void Cercle::setCentre(){
    
    centre.setX(random(10,0));
    centre.setY(random(10,0));
    
	}

Point Cercle::getCentre(){
	return centre;
	}


void Cercle::setRayon(){
	rayon=random(5,1);
	}


int Cercle::getRayon(){
	return rayon;
	}	

void Cercle::setCouleur(){
	string color[7]={"blanc","bleu","vert","rouge","jaune","orange","noir"};
	
	couleur=color[random(6,0)];
	}
		
string Cercle::getCouleur(){
	return couleur;
	}
	
