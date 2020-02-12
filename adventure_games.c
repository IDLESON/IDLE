//搭建框架
//导入mycon库函数
 
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS

    //定义句柄变量
HANDLE hOut = NULL;

	//定义窗口大小 
void set_size(int width,int highth)
{
    char chCmd[32];
	sprintf(chCmd,"mode con cols=%d lines=%d",width,highth);
	system(chCmd);
}
	//定义窗口标题 
void set_title(char title[])
{
	SetConsoleTitleA(title);
}
	//光标指向XY 
void gotoxy(int x, int y)
{
    COORD pos;

    //获取标准输出句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    pos.X = x;
    pos.Y = y;
    //设置光标的位置
    SetConsoleCursorPosition(hOut, pos); 
}
//隐藏光标
void hide_cursor(void)
{
	//光标信息变量
    CONSOLE_CURSOR_INFO cursorInfo;

    //获取标准输出句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    //获取当前光标信息
    GetConsoleCursorInfo(hOut, &cursorInfo);


    //设置光标不可见
    cursorInfo.dwSize = 25;
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(hOut, &cursorInfo);
    
}
//显示光标
void show_cursor(void)
{
	//光标信息变量
    CONSOLE_CURSOR_INFO cursorInfo;

    //获取标准输出句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    //获取当前光标信息
    GetConsoleCursorInfo(hOut, &cursorInfo);


    //设置光标可见
    cursorInfo.dwSize = 25;
    cursorInfo.bVisible = 1;
    SetConsoleCursorInfo(hOut, &cursorInfo);
} 
//背景前景颜色
void set_color(void)//int bcolor, int fcolor
{
	system("color f4");
} 

//清屏 
void cls(void)
{
system("cls");
}

//延迟
void delay(int dtime)
{
Sleep(dtime);
} 
