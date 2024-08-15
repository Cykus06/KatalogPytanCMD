#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "Interface.h"

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
#endif

    Interface inter;
    inter.execute();

    return 0;
}