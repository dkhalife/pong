#include "Player.h"
#include <Windows.h>
#include <gl/glut.h>
#include <gl/glut.h>

Player::Player(int num) : r(Raquet(0,0)){
	score = 0;

	// move the raquet to the right position depending on the player
	if(num == 1){
		r.move(-0.90f, 0);
	}
	else{
		r.move(0.90f, 0);
	}
}

Player::~Player(){
}

void Player::draw() const {
	r.draw();
}

void Player::incScore() {
	++score;
}

void Player::moveUp(){
	if(r.getY() + r.getHeight() / 2 < 1.0f){
		r.move(r.getX(), r.getY() + 0.03f);
	}
}

void Player::moveDown(){
	if(r.getY() - r.getHeight() / 2 > -1.0f){
		r.move(r.getX(), r.getY() - 0.03f);
	}
}

Raquet Player::getRaquet() const {
	return r;
}