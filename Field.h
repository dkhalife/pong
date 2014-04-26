#ifndef FIELD_H
#define FIELD_H

class Field {
	private:
		int width;
		int height;

	public:
		Field(int width, int height);
		~Field();
		void draw() const;
};

#endif