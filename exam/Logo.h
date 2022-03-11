#pragma once

#include "Func.h"

enum HorizontalAlignment
{
	Center, Left, Right
};

class Logo
{
public:
	static void print(std::string logo, int x, int y, ConsoleColor color);
	static void print(std::string logo, HorizontalAlignment hAlignment, int y, ConsoleColor color);
	Logo();
	~Logo();
};

