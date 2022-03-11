#pragma once
#include "Logo.h"

using namespace std;


void SetCursorVisibility(bool v)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
	structCursorInfo.bVisible = v;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
}

class Menu
{
public:
	static int select_vertical(vector <string> menu, HorizontalAlignment ha, int y = 12)
	{
		setlocale(0, "");
		SetCursorVisibility(0);
		int maxLen = 0;
		for (size_t i = 0; i < menu.size(); i++)
		{
			if (menu[i].length() > maxLen)
				maxLen = menu[i].length();
		}
		int x = 0;
		switch (ha)
		{
		case Center: x = 40 - maxLen / 2; break;
		case Left:   x = 0;	              break;
		case Right:  x = 80 - maxLen;     break;
		}
		char c;
		int pos = 0;
		do
		{
			for (int i = 0; i < menu.size(); i++)
			{
				if (i == pos)
				{
					SetColor(0, 15);
					gotoxy(x, y + i);
					cout << setw(maxLen) << left;
					gotoxy(x, y + i);
					cout << menu[i] << endl;
					SetColor(15, 0);
				}
				else
				{
					SetColor(15, 0);
					gotoxy(x, y + i);
					cout << setw(maxLen) << left;
					gotoxy(x, y + i);
					cout << menu[i] << endl;
					SetColor(0, 15);
				}
			}
			c = _getch();
			switch (c)
			{
			case 72: if (pos > 0)               pos--; break;
			case 80: if (pos < menu.size() - 1) pos++; break;
			case 13: break;
			case 27:SetColor(15,0); return -1; break;
			}
		} while (c != 13);
		SetColor(7, 0);

		for (size_t i = 0; i < 2; i++)
		{
			SetColor(15, 0);
			gotoxy(x, y + pos);
			cout << setw(maxLen) << left;
			gotoxy(x, y + pos);
			cout << menu[pos] << endl;
			Sleep(300);
			SetColor(0, 15);
			gotoxy(x, y + pos);
			cout << setw(maxLen) << left;
			gotoxy(x, y + pos);
			cout << menu[pos] << endl;
			SetColor(15, 0);
			Sleep(300);
		}
		SetCursorVisibility(1);
		return pos;

	}

	int select_gorizontal(vector<string> menu)
	{
		int max_len = 0;
		for (int i = 0; i < menu.size(); i++)
			max_len += menu[i].length();
		if (max_len > 80 - menu.size() - 1)
			int a = 1;
	}
};