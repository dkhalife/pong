#include "Raquet.h"
#include <Windows.h>
#include <gl/glut.h>
#include <gl/glut.h>

Raquet::Raquet(float x, float y){
	this->x = x;
	this->y = y;

	width = 0.05f;
	height = 0.2f;
}

Raquet::~Raquet(){
}

void Raquet::draw() const {
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
		glVertex3f(this->x-this->width/2, this->y-this->height/2, 0);
		glVertex3f(this->x-this->width/2, this->y+this->height/2, 0);
		glVertex3f(this->x+this->width/2, this->y+this->height/2, 0);
		glVertex3f(this->x+this->width/2, this->y-this->height/2, 0);
	glEnd();
}

void Raquet::move(float x, float y){
	this->x = x;
	this->y = y;
}

float Raquet::getX() const {
	return x;
}

float Raquet::getY() const {
	return y;
}

float Raquet::getWidth() const {
	return width;
}

float Raquet::getHeight() const {
	return height;
}