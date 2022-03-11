#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>

using namespace std;
enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background);

void gotoxy(int x, int y);
