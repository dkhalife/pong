#include "Raquet.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
	private:
		int score;
		Raquet r;

	public:
		Player(int num);
		~Player();
		void draw() const;
		void incScore();
		void moveUp();
		void moveDown();
		Raquet getRaquet() const;
};

#endif