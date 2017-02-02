#pragma once
#include "ofMain.h"

class frameBuffer {
public:
	void setup();
	void update();
	void draw();

	void putpixel(const int& x, const int& y, const ofColor& color);
	void clear(const ofColor& color);

	void midLine(int x0, int y0, int x1, int y1);
	void angulos();


private:
	ofImage _img;
	void FASTputpixel(const int& x, const int& y, const ofColor& color);

};
