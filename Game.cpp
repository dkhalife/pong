#include "Game.h"
#include "Field.h"
#include <Windows.h>
#include <gl/GLU.h>
#include <gl/glut.h>

float player1_delta = 0.0f;
float player2_delta = 0.0f;

Game::Game(int width, int height) : player1(Player(1)), player2(Player(2)), field(Field(width, height)), ball(Ball(0,0)){
}

Game::~Game(){
}

void Game::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	field.draw();
	player1.draw();
	player2.draw();

	if(ball.collidesWith(player1.getRaquet()) || ball.collidesWith(player2.getRaquet())){
		ball.setSpeed(-ball.getSpeedX(), ball.getSpeedY());
	}
	else if(ball.getY() >= 0.95f || ball.getY() <= -0.95f){
		ball.setSpeed(ball.getSpeedX(), -ball.getSpeedY());
	}

	// Player loses
	if(ball.getX() <= -0.9f){
		//exit(1);
		ball.setSpeed(0, 0);
	}
	else if(ball.getX() >= 0.9f){
		//exit(2);
		ball.setSpeed(0, 0);
	}

	if(player1_delta > 0){
		player1.moveUp();
	}
	else if(player1_delta < 0 ){
		player1.moveDown();
	}

	if(player2_delta > 0){
		player2.moveUp();
	}
	else if(player2_delta < 0 ){
		player2.moveDown();
	}

	ball.draw();
	drawScores();

	// Finish drawing by sending the data from the buffer
	glutSwapBuffers();
}

void Game::drawScores() const {
	// TODO
}

void Game::changeSize(int width, int height) const {
	if(height == 0){
		height = 1;
	}

	float ratio = float(width / height);

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, width, height);

	// Set the correct perspective.
	gluPerspective(45, ratio, 10, 10);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void Game::processNormalKeys(unsigned char key, int x, int y){
	switch(key){
		case 'w':
			player1_delta = 1;
		break;

		case 's':
			player1_delta = -1;
		break;

		case 27:
			exit(0);
		break;
	}
}

void Game::processSpecialKeys(int key, int x, int y){
	switch(key){
		case GLUT_KEY_UP:
			player2_delta = 1;
		break;

		case GLUT_KEY_DOWN:
			player2_delta = -1;
		break;
	}
}

void Game::processSpecialUpKeys(int key, int x, int y) {
	switch (key) {
		case 'w' :
		case 's' : 
			player1_delta = 0.0f;
		break;

		case GLUT_KEY_UP : 
		case GLUT_KEY_DOWN : 
			player2_delta = 0;
		break;
	}
}

void Game::processNormalUpKeys(unsigned char key, int x, int y) {
	switch (key) {
		case 'w' :
		case 's' : 
			player1_delta = 0.0f;
		break;
	}
}