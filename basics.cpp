#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

GLfloat red = 1.0f, green = 1.0f, blue = 1.0f;

void renderScene(){
	static GLfloat angle = 0.0f;

	// Clear the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Set the camera
	gluLookAt(0.0f, 0.0f, 10.0f,
		  0.0f, 0.0f, 0.0f,
		  0.0f, 1.0f, 0.0f);

	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	// Draw triangle
	glColor3f(red, green, blue);
	glBegin(GL_TRIANGLES);
		glVertex3f(-2, -2, 0.0);
		glVertex3f(2, 0.0, 0.0);
		glVertex3f(0.0, 2, 0.0);
	glEnd();

	angle += 0.3f;

	// Finish drawing by sending the data from the buffer
	glutSwapBuffers();
}

void changeSize(int w, int h){
	if(h == 0) h = 1;

	float ratio = 1.0 * w / h;

	// Use the projection matrix
	glMatrixMode(GL_PROJECTION);

	// Load identity matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0,0,w,h);

	// Set the correct perspective
	gluPerspective(45,ratio,1,1000);

	// Go back to the default mode
	glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y){
	int mod = glutGetModifiers();

	switch(key){
		case 27: //Esc
			exit(0);
		break;

		case 'r':
			if(mod == GLUT_ACTIVE_ALT){
				red = 0;
			}
			else{
				red = 1;
			}
		break;

		case 'g':
			if(mod == GLUT_ACTIVE_ALT){
				green = 0;
			}
			else{
				green = 1;
			}
		break;

		case 'b':
			if(mod == GLUT_ACTIVE_ALT){
				blue = 0;
			}
			else{
				blue = 1;
			}
		break;
	}
}

void processSpecialKeys(int key, int x, int y){
	int mod = glutGetModifiers();

	switch(key){
		case GLUT_KEY_F1:
			if(mod == (GLUT_ACTIVE_CTRL | GLUT_ACTIVE_ALT)){
				red = abs(1 - red);
				green = abs(1 - green);
				blue = abs(1 - blue);
			}
			else{
				red = 1.0;
				green = 0.0;
				blue = 0.0;
			}
		break;

		case GLUT_KEY_F2:
			red = 0.0;
			green = 1.0;
			blue = 0.0;
		break;

		case GLUT_KEY_F3:
			red = 0.0;
			green = 0.0;
			blue = 1.0;
		break;
	}
}

int main(int argc, char **argv){
	// Init Glut and create window
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Pong game");


	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	// enter Glut event processing cycle
	glutMainLoop();

	return 0;
}