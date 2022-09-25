#pragma once

#include <windows.h>
#include <graphics.h>
#include <utility>
#include <vector>

namespace EasyRGB
{
	void EditPixel(int x, int y, COLORREF color)
	{
		putpixel(3 * x, y * 3, RGB(GetRValue(color), 0, 0));
		putpixel(3 * x, y * 3 + 1, RGB(GetRValue(color), 0, 0));
		putpixel(3 * x, y * 3 + 2, RGB(GetRValue(color), 0, 0));
		putpixel(3 * x + 1, y * 3, RGB(0, GetGValue(color), 0));
		putpixel(3 * x + 1, y * 3 + 1, RGB(0, GetGValue(color), 0));
		putpixel(3 * x + 1, y * 3 + 2, RGB(0, GetGValue(color), 0));
		putpixel(3 * x + 2, y * 3, RGB(0, 0, GetBValue(color)));
		putpixel(3 * x + 2, y * 3 + 1, RGB(0, 0, GetBValue(color)));
		putpixel(3 * x + 2, y * 3 + 2, RGB(0, 0, GetBValue(color)));
	}
	COLORREF GetPixel(int x, int y)
	{
		return RGB(GetRValue(getpixel(x * 3, y * 3)), GetGValue(getpixel(x * 3 + 1, y * 3)), GetBValue(getpixel(x * 3 + 2, y * 3)));
	}
	void DefaultImage2PixelRGB()
	{
		std::vector<std::vector<COLORREF>> colors;
		std::vector<COLORREF> copytocolors;
		int x = getwidth();
		int y = getheight();
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				copytocolors.push_back(getpixel(i, j));
			}
			colors.push_back(copytocolors);
			copytocolors.clear();
		}
		closegraph();
		initgraph(x * 3, y * 3);
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				EditPixel(i, j, colors[i][j]);
			}
		}
	}
	void PixelRGB2DefaultImage(bool _Createnew = true)
	{
		std::vector<std::vector<COLORREF>> colors;
		std::vector<COLORREF> copytocolors;
		int x = getwidth();
		int y = getheight();
		auto decolor = [](int x, int y) -> COLORREF
		{
			return RGB(GetRValue(getpixel(x * 3, y * 3)), GetGValue(getpixel(x * 3 + 1, y * 3)), GetBValue(getpixel(x * 3 + 2, y * 3)));
		};
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				copytocolors.push_back(decolor(i, j));
			}
			colors.push_back(copytocolors);
			copytocolors.clear();
		}
		if (_Createnew) 
		{
			closegraph();
			initgraph(x / 3, y / 3);
		}
		else
		{
			cleardevice();
		}
		for (int i = 0; i < x / 3; i++)
		{
			for(int j = 0; j < y / 3; j++)
			{
				putpixel(i, j, colors[i][j]);
			}
		}
	}
}