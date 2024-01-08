#include <iostream>
#include <string>

class Point{
		
	private:
		int x;
		int y;	
	
	public:
		Point(){}
		~Point(){}
		
		int getX();
		void setX(int xTmp);
	
		int getY();
		void setY(int yTmp);
	};

int Point::getX(){
	return x;
	}

void Point::setX(int xTmp){
	x=xTmp;
	}
	
int Point::getY(){
	return y;
	}

void Point::setY(int yTmp){
	y=yTmp;
	}	
