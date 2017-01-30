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
	int d = 2 * dy - dx;
	int DeltaNE = 2 * dy;
	int DeltaE = 2 * (dy - dx);
	int x = x0;
	int y = y0;

	putpixel(x0, y0, ofColor::blue);
	for (x = x0; x <= x1; x++) {


		while (x < x1)
		{
			if (d <= 0)
			{
				d = d + DeltaE;
				x++;
			}

			else
			{
				d = d + DeltaNE;
				x++;
				y++;
			}

			putpixel(x, y, ofColor::blue);



		}
	}
}

void frameBuffer::FASTputpixel(const int & x, const int & y, const ofColor & color)
{
	_img.setColor(x, y, color);
}
