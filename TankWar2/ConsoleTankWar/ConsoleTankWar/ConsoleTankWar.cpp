// ConsoleTankWar.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<cmath>
#include<time.h>

#define PI 3.14159265358979

int main()
{
	initgraph(640, 480);

	// 定义图像

	IMAGE img1, img2;



	// 从文件加载图像

	loadimage(&img1, _T("C:\\Users\JimmyLin\Desktop\CU.JPG"));

	// 旋转图像 30 度 (PI / 6)

	rotateimage(&img2, &img1, PI / 6);



	// 显示旋转后的图像

	putimage(0, 0, &img2);


	while (1)
	{
	if	(GetAsyncKeyState(VK_UP)) break;
	}
	closegraph();
    return 0;
}

