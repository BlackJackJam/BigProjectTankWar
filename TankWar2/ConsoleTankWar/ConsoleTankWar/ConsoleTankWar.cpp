// ConsoleTankWar.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<cmath>
#include<time.h>

#define PI 3.1415926

int main()
{
	initgraph(640, 480);
	setlinestyle(PS_SOLID, 10);			// 设置线宽为 10，这样效果明显
	setlinecolor(GREEN);				// 设置画线颜色为绿色
	rectangle(100, 100, 200, 200);		// 画一个矩形，当做背景图案

	setwritemode(R2_XORPEN);			// 设置 XOR 绘图模式
	setlinecolor(RED);					// 设置画线颜色为红色

	line(50, 0, 200, 300);				// 画线
	_getch();							// 等待按任意键
	line(50, 0, 200, 300);
	Sleep(1000);
	_getch();
	line(50, 0, 200, 300);
	while (1)
	{
	if	(GetAsyncKeyState(VK_UP)) break;
	}
	closegraph();
    return 0;
}

