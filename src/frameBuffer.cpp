#include "frameBuffer.h"
void frameBuffer::setup()
{
	_img.allocate(1024, 768, ofImageType::OF_IMAGE_COLOR_ALPHA);
	clear(ofColor::black);
}

void frameBuffer::update()
{
}

void frameBuffer::draw()
{
	/*for (int x = 0; x < 1024; x++) {
	putpixel(x, 768 / 2, ofColor::green);
	}*/
}

void frameBuffer::putpixel(const int & x, const int & y, const ofColor & color)
{
	_img.setColor(x, y, color);
	_img.update();
	_img.draw(ofPoint(0, 0, 0));
}

void frameBuffer::clear(const ofColor & color)
{
	for (int y = 0; y < 768; y++)
		for (int x = 0; x < 1024; x++)
			FASTputpixel(x, y, color);
	_img.update();
	_img.draw(ofPoint(0, 0, 0));
}

void frameBuffer::midLine(int x0, int y0, int x1, int y1)
{

	int dx = (x1 - x0);
	int dy = (y1 - y0);
	int d = 0;
	int DeltaNE = dy;
	int DeltaE = (dy - dx);

	int x = x0;
	int y = y0;

	//cuadrante 4
	if (y1 > y0 && x1 >= x0) {

		// octante 8
		if (dx > dy) {

			for (int x = x0; x <= x1; x++) {
				putpixel(x, y, ofColor::blue);
				if (d > 0) {
					d = d + DeltaE;
					y++;
				}
				else d = d + DeltaNE;
			}
		}
		// octante 7
		else if (dx <= dy) {
			for (int y = y0; y <= y1; y++) {
				putpixel(x, y, ofColor::blue);
				if (d > 0) {
					d = d + dx - dy;
					x++;
				}
				else d = d + dx;
			}
		}
	}

	//cuadrante 3
	else if (y1 >= y0 && x1 < x0) {

		// octante 6
		if (dx > dy*-1) {

			for (int y = y0; y <= y1; y++) {
				putpixel(x, y, ofColor::red);
				if (d < 0) {
					d = d + dx - dy*-1;
					x--;
				}
				else d = d + dx;
			}
		}
		// octante 5
		else if (dx <= dy*-1) {
			for (int x = x0; x >= x1; x--) {
				putpixel(x, y, ofColor::red);
				if (d < 0) {
					d = d - dx - dy;
					y++;
				}
				else d = d - dy;
			}
		}
	}


	//cuadrante 2
	else if (y1 < y0 && x1 <= x0) {

		// octante 4
		if (dx < dy) {

			for (int x = x0; x >= x1; x--) {
				putpixel(x, y, ofColor::green);
				if (d < 0) {
					d = d + dy - dx;
					y--;
				}
				else d = d + DeltaNE;
			}
		}
		// octante 3
		else if (dx >= dy) {
			for (int y = y0; y >= y1; y--) {
				putpixel(x, y, ofColor::green);
				if (d < 0) {
					d = d + dx - dy;
					x--;
				}
				else d = d + dx;
			}
		}
	}

	//cuadrante 1
	else if (y1 <y0 && x1 >= x0) {

		// octante 2
		if (dx*-1 > dy) {

			for (int y = y0; y >= y1; y--) {
				putpixel(x, y, ofColor::yellow);
				if (d > 0) {
					d = d + dx - dy*-1;
					x++;
				}
				else d = d + dx;
			}
		}
		// octante 1
		else if (dx*-1 <= dy) {
			for (int x = x0; x <= x1; x++) {
				putpixel(x, y, ofColor::yellow);
				if (d > 0) {
					d = d - dy - dx;
					y--;
				}
				else d = d - dy;
			}
		}
	}
}






void frameBuffer::angulos()
{
	int xc = ofGetWidth() / 2;
	int yc = ofGetHeight() / 2;
	int x0 = 0;
	int y0 = 0;
	for (float angulo = 0; angulo < 360; angulo = angulo ++) {
		int x1 = 50 * cos(angulo *PI / 180.0);
		int y1 = 50 * sin(angulo *PI / 180.0);

		midLine(x0 + xc, y0 + yc, x1 + xc, y1 + yc);
	}
}

void frameBuffer::FASTputpixel(const int & x, const int & y, const ofColor & color)
{
	_img.setColor(x, y, color);
}
