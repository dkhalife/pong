#include "Game.h"
#include <time.h>
#include <cmath>
#include <Windows.h>
#include <gl/glut.h>
#include <gl/glut.h>

int width = 600;
int height = 400;
Game g = Game(width, height);

void changeSize(int width, int height){
	g.changeSize(width, height);
}

void renderScene(int value){
	g.draw();
	glutTimerFunc(30, renderScene, value);
}

void display(){
	g.draw();
}

void processNormalKeys(unsigned char key, int x, int y){
	g.processNormalKeys(key, x, y);
}

void releaseNormalKeys(unsigned char key, int x, int y){
	g.processNormalUpKeys(key, x, y);
}

void processSpecialKeys(int key, int x, int y){
	g.processSpecialKeys(key, x, y);
}

void releaseSpecialKeys(int key, int x, int y){
	g.processSpecialUpKeys(key, x, y);
}

int main(int argc, char** argv){
	srand(time(0));

	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Pong game");


	// register callbacks
	glutDisplayFunc(display);
	glutReshapeFunc(changeSize);
	//glutIdleFunc(renderScene);

	int value = 0;
	glutTimerFunc(42, renderScene, value);

	glutKeyboardFunc(processNormalKeys);
	glutKeyboardUpFunc(releaseNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseSpecialKeys);

	// enter Glut event processing cycle
	glutMainLoop();


	return 0;
}