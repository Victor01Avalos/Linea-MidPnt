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
	for (int x = 0; x < 1024; x++) {
		putpixel(x, 768 / 2, ofColor::green);
	}
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

	int dx = x1 - x0;
	int dy = y1 - y0;
	int d =  dy - dx;
	int DeltaNE = 2 * dy;
	int DeltaE = 2 * (dy - dx);
	int x = x0;
	int y = y0;

	putpixel(x0, y0, ofColor::blue);
	


		while (x <= x1)
		{
			x = x + 1;
			if (d >= 0)
			{
				d = d + DeltaE;
			}

			else
			{
				d = d + DeltaNE;
				y++;
			}

			putpixel(x, y, ofColor::blue);



		}
	}

void frameBuffer::angulos()
{
	int xc = ofGetWidth() / 2;
	int yc = ofGetHeight() / 2;
	int x0 = 0;
	int y0 = 0;
	for (float angulo = 0; angulo < 360; angulo++) {
		int x1 = 50 * cos(angulo *PI / 180.0);
		int y1 = 50 * sin(angulo *PI / 180.0);

		midLine(x0 + xc, y0 + yc, x1 + xc, y1 + yc);
	}
}


void frameBuffer::FASTputpixel(const int & x, const int & y, const ofColor & color)
{
	_img.setColor(x, y, color);
}
