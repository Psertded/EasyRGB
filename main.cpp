#include "easyrgb_define.h"
#include <conio.h>

int main()
{
	initgraph(255,255);
	for (int i = 0; i < 255; i++)
	{

		for (int j = 0; j < 255; j++)
		{
			putpixel(i, j, RGB(i, j, 0));
		}
	}
	EasyRGB::DefaultImage2PixelRGB();
	Sleep(5000);
	EasyRGB::PixelRGB2DefaultImage();
	_getch();
	closegraph();
	return 0;
}