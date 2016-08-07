#include "Point.h"



void Point::drawpoint(){
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex3f(x, y, 0.0);
	glEnd();
}
Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}
Point::~Point(){

}


