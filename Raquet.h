#ifndef RAQUET_H
#define RAQUET_H

class Raquet {
	private:
		float x;
		float y;
		float width;
		float height;

	public:
		Raquet(float x, float y);
		~Raquet();
		void draw() const;
		float getX() const;
		float getY() const;
		float getWidth() const;
		float getHeight() const;
		void move(float x, float y);
};

#endif