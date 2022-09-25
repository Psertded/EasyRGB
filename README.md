# EasyRGB

---

> This program uses EasyX as the graphics library, so please configure [EasyX](https://easyx.cn) before use!!!
>
> [Press ME to download the setup](https://easyx.cn/download/EasyX_20220901.exe)

This project is very simple, isn't it? In the future, I will try to implement the function of drawing graphics directly in it (or implement some functions of the original EasyX).<br>
This program can convert a normal bitmap into a bitmap where each RGB pixel is visible.

## Warnings

>- Please use Release to compile, otherwise the window may not be found.

## Renderings

- <b>Default</b><br>
![image](https://user-images.githubusercontent.com/110461934/192146968-f70f8890-af7d-42b8-a3eb-7fbd4220df60.png)

- <b>Converted</b><br>
![image](https://user-images.githubusercontent.com/110461934/192147015-d7c018e9-9e30-4b3f-95ec-7a770383d2a0.png)

##### The RGB pixel can see now!!!

![image](https://user-images.githubusercontent.com/110461934/192147170-e59fc423-65c7-4cce-b70c-a9e7a51ca0b1.png)

---

You can also directly get the color value of the scattered RGB pixels (the original xy coordinates, 3:1 (after the scattering, the original), no need to multiply the coordinates by 3)<br>
Now that you can get it directly, you can also edit the RGB pixels directly!(the original xy coordinates!!!)

---

### Here is an example.

[Click me to view](main.cpp)

```
#include "EasyRGB.h"
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
```


Translator: Google Translate(Chinese to English)
