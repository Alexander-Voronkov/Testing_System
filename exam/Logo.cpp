#include "Logo.h"
#include "Func.h"

void Logo::print(std::string logo, int x, int y0, ConsoleColor color)
{
	SetColor(color, 0);
	for (size_t i = 0; i < logo.size(); i++)
	{
		int y = y0;
		switch (logo[i])
		{
		case 'a': case 'A':
			gotoxy(x, y++); cout << "  #  ";
			gotoxy(x, y++); cout << " # # ";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#   #";
			break;
		case 'b': case 'B':
			gotoxy(x, y++); cout << "#### ";
			gotoxy(x, y++); cout << "#  # ";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#####";
			break;
		case 'c': case 'C':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#####";
			break;
		case 'd': case 'D':
			gotoxy(x, y++); cout << "####";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#### ";
			break;
		case 'e': case 'E':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#####";
			break;
		case 'f': case 'F':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#### ";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#    ";
			break;
		case 'g': case 'G':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#####";
			break;
		case 'h': case 'H':
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			break;
		case 'i': case 'I':
			gotoxy(x, y++); cout << " ### ";
			gotoxy(x, y++); cout << "  #  ";
			gotoxy(x, y++); cout << "  #  ";
			gotoxy(x, y++); cout << "  #  ";
			gotoxy(x, y++); cout << " ### ";
			break;
		case 'j': case 'J':
			gotoxy(x, y++); cout << "   ###";
			gotoxy(x, y++); cout << "    # ";
			gotoxy(x, y++); cout << "    # ";
			gotoxy(x, y++); cout << " #  # ";
			gotoxy(x, y++); cout << "  ##  ";
			break;
		case 'k': case 'K':
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#  # ";
			gotoxy(x, y++); cout << "###  ";
			gotoxy(x, y++); cout << "#  # ";
			gotoxy(x, y++); cout << "#   #";
			break;
		case 'l': case 'L':
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#####";
			break;
		case 'm': case 'M':
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "## ##";
			gotoxy(x, y++); cout << "# # #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			break;
		case 'n': case 'N':
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "##  #";
			gotoxy(x, y++); cout << "# # #";
			gotoxy(x, y++); cout << "#  ##";
			gotoxy(x, y++); cout << "#   #";
			break;
		case 'o': case 'O':case'0':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#####";
			break;
		case 'p': case 'P':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#    ";
			break;
		case 'q': case 'Q':
			gotoxy(x, y++); cout << " ###";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#  ##";
			gotoxy(x, y++); cout << " ####";
			break;
		case 'r': case 'R':
			gotoxy(x, y++); cout << "#### ";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#### ";
			gotoxy(x, y++); cout << "#  # ";
			gotoxy(x, y++); cout << "#   #";
			break;
		case 's': case 'S':
			gotoxy(x, y++); cout << " ####";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << " ### ";
			gotoxy(x, y++); cout << "    # ";
			gotoxy(x, y++); cout << "####";
			break;
		case 't': case 'T':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "  #  ";
			gotoxy(x, y++); cout << "  #  ";
			gotoxy(x, y++); cout << "  #  ";
			gotoxy(x, y++); cout << "  #  ";
			break;
		case 'u': case 'U':
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << " ### ";
			break;
		case 'v': case 'V':
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << " # # ";
			gotoxy(x, y++); cout << "  # ";
			break;
		case 'w': case 'W':
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "# # #";
			gotoxy(x, y++); cout << "## ## ";
			gotoxy(x, y++); cout << "#   #";
			break;
		case 'x': case 'X':
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << " # # ";
			gotoxy(x, y++); cout << "  #  ";
			gotoxy(x, y++); cout << " # # ";
			gotoxy(x, y++); cout << "#   #";
			break;
		case 'y': case 'Y':
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << " # # ";
			gotoxy(x, y++); cout << "  #  ";
			gotoxy(x, y++); cout << "  #  ";
			gotoxy(x, y++); cout << "  #  ";
			break;
		case 'z': case 'Z':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "   # ";
			gotoxy(x, y++); cout << "  #  ";
			gotoxy(x, y++); cout << " #  ";
			gotoxy(x, y++); cout << "#####";
			break;
		case '1':
			gotoxy(x, y++); cout << "   ##";
			gotoxy(x, y++); cout << "  # #";
			gotoxy(x, y++); cout << " #  #";
			gotoxy(x, y++); cout << "    #";
			gotoxy(x, y++); cout << "    #"; break;
		case '2':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "    #";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#####"; break;
		case '3':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "    #";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "    #";
			gotoxy(x, y++); cout << "#####"; break;
		case '4':
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "    #";
			gotoxy(x, y++); cout << "    #"; break;
		case '5':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "    #";
			gotoxy(x, y++); cout << "#####"; break;
		case '6':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#    ";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#####"; break;
		case '7':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "    #";
			gotoxy(x, y++); cout << "    #";
			gotoxy(x, y++); cout << "    #";
			gotoxy(x, y++); cout << "    #"; break;
		case '8':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#####";
			break;
		case '9':
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "#   #";
			gotoxy(x, y++); cout << "#####";
			gotoxy(x, y++); cout << "    #";
			gotoxy(x, y++); cout << "#####";
			break;
		case '.':
			gotoxy(x, y++); cout << "     ";
			gotoxy(x, y++); cout << "     ";
			gotoxy(x, y++); cout << "     ";
			gotoxy(x, y++); cout << "     ";
			gotoxy(x, y++); cout << "  #  ";
			break;
		default:
			break;
		}
		x += 6;
	}
}

void Logo::print(std::string logo, HorizontalAlignment hAlight, int y, ConsoleColor color)
{
	int x = 0;
	switch (hAlight)
	{
	case Center:
		x = 42- logo.length()/2 * 6;
		break;
	case Left:
		x = 0;
		break;
	case Right:
		x = 80 - logo.length() * 6;
		break;
	default:
		break;
	}
	print(logo, x, y, color);
}
Logo::Logo() {}
Logo::~Logo() {}