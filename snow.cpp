#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

// angle for camera rotation
GLfloat angle = 0.0f;
// camera's direction
GLfloat lx = 0.0f, lz = -1.0f;
// XZ position of the camera
GLfloat cameraX = 0.0f, cameraZ = 5.0f;

void drawSnowMan(){
	// Snowman is White
	glColor3f(1.0f, 1.0f, 1.0f);

	// Draw the body
	glTranslatef(0.0f, 0.75f, 0.0f);
	glutSolidSphere(0.75f, 20, 20);

	// Draw the head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f, 20, 20);

	// Draw the eyes
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f); // eyes are black

	// 1st eye
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);

	// 2nd eye
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);

	glPopMatrix();

	// Draw the nose
	glColor3f(1.0f, 0.5f , 0.5f); // his nose is orange
	glRotatef(0.0f,1.0f, 0.0f, 0.0f); // rotate perpendicularly
	glutSolidCone(0.08f,0.5f,10,2);
}

void renderScene(void){
	// Clear color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset the transforms
	glLoadIdentity();

	// Set the camera
	gluLookAt(cameraX, 1.0f, cameraZ,
		  cameraX+lx, 1.0f, cameraZ+lz,
		  0.0f, 1.0f, 0.0f);

	// Draw the ground
	glColor3f(0.6f, 0.6f, 0.6f); // grey

	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	// Draw the snow men
	for(int i=-3; i<3; ++i){
		for(int j=-3; j<3; ++j){
			glPushMatrix();

			glTranslatef(i*10.0, 0, j*10.0);
			drawSnowMan();

			glPopMatrix();
		}
	}

	glutSwapBuffers();
}

void processSpecialKeys(int key, int eventX, int eventY){
	float speed = 0.1f;

	switch(key){
		case GLUT_KEY_LEFT :
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
		break;

		case GLUT_KEY_RIGHT :
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
		break;

		case GLUT_KEY_UP :
			cameraX += lx * speed;
			cameraZ += lz * speed;
		break;

		case GLUT_KEY_DOWN :
			cameraX -= lx * speed;
			cameraZ -= lz * speed;
		break;
	}
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

int main(int argc, char **argv) {
	// initialisation
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("World of snowmen");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}