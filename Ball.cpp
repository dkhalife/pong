#include "Ball.h"
#include <Windows.h>
#include <gl/glut.h>
#include <gl/glut.h>
#include <cmath>

Ball::Ball(float x, float y){ 
	this->x = x;
	this->y = y;
	this->dx = (rand()%4 + 4) * 0.01f - 0.04f;
	this->dy = (rand()%4 + 4) * 0.01f - 0.04f;
	this->size = 0.05f;
}

Ball::~Ball(){
}

float Ball::getX() const {
	return this->x;
}


float Ball::getY() const {
	return this->y;
}

void Ball::move(float x, float y){
	this->x = x;
	this->y = y;
}

float Ball::getSpeedX() const {
	return this->dx;
}

float Ball::getSpeedY() const {
	return this->dy;
}

void Ball::setSpeed(float dx, float dy){
	this->dx = dx;
	this->dy = dy;
}

void Ball::draw() {
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
		glVertex3f(this->x - this->size/2, this->y - this->size/2, 1);
		glVertex3f(this->x + this->size/2, this->y - this->size/2, 1);
		glVertex3f(this->x + this->size/2, this->y + this->size/2, 1);
		glVertex3f(this->x - this->size/2, this->y + this->size/2, 1);
	glEnd();

	this->x += this->dx;
	this->y += this->dy;
}

bool Ball::collidesWith(Raquet r) const {
	// Check same height
	if((this->y-this->size/2) - (r.getY() - r.getHeight()/2) >= 0 && (this->y+this->size/2) - (r.getY() + r.getHeight()/2) <= 0){

		// Case for left player
		if(r.getX() < 0){
			if((r.getX() + r.getWidth()/2) >= this->x - this->size/2){
				return true;
			}
		}

		// Case for right player
		else{
			if((r.getX() - r.getWidth()/2) <= this->x + this->size/2){
				return true;
			}
		}
	}

	return false;
}