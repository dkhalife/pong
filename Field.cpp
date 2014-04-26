#include "Field.h"
#include <Windows.h>
#include <gl/GLU.h>
#include <gl/glut.h>

Field::Field(int width, int height){
	this->width = width;
	this->height = height;
}

Field::~Field(){
}
	
void Field::draw() const {
	// Draw triangle
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
}