#ifndef BALL_H
#define BALL_H

#include "Raquet.h"

class Ball {
	private:
		float x;
		float y;
		float dx;
		float dy;
		float size;

	public:
		Ball(float x, float y);
		~Ball();
		float getX() const;
		float getY() const;
		void move(float x, float y);
		float getSpeedX() const;
		float getSpeedY() const;
		void setSpeed(float dx, float dy);
		void draw();
		bool collidesWith(Raquet r) const;
};

#endif;