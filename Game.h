#include "Player.h"
#include "Field.h"
#include "Ball.h"

#ifndef GAME_H
#define GAME_H

class Game {
	private:
		int width;
		int height;
		Player player1;
		Player player2;
		Field field;
		Ball ball;
		void drawScores() const;

	public:
		Game(int width, int height);
		~Game();
		void draw();
		void changeSize(int width, int height) const;
		void processNormalKeys(unsigned char key, int x, int y);
		void processSpecialKeys(int key, int x, int y);
		void processSpecialUpKeys(int key, int x, int y);
		void processNormalUpKeys(unsigned char key, int x, int y);
};

#endif 