/**
 * @details Basical function
*/
#ifndef _MDLP_HEADER
#define _MDLP_HEADER

#include <atomic>
#include <cassert>
#include <conio.h>
#include <cstring>
#include <iostream>
#include <io.h>
#include <map>
#include <set>
#include <string>
#include <thread>
#include <vector>
#include <windows.h>
#include <winspool.h>
using namespace std;

const int OneSecond = 1000;

const int MDFallTime = 1500;
const int FourKeyFallTime = 1000;
const int Columns = 45;
const int Lines = 15;
const double MDSpeed = (double)Columns / MDFallTime;
const double FourKeySpeed = (double)Lines / FourKeyFallTime;


int start_time;
int NowTime()
{
    return clock()-start_time;
}

char lower(char c)
{
    return (c>=65 and c<=90) ? c+32 : c;
}

void Print(string s, int times)
{
    for(auto v : s)
    {
        cout << v;
        if(_kbhit()) times = INT_MAX;
        Sleep(OneSecond/times);
    }
}

char WaitForInput()
{
    char ch = 0;
    while(true)
    {
        if(!_kbhit()) continue;
        else { ch = _getch(); break; }
    }
    return ch;
}

void ClearScreen()
{
	COORD coordScreen = {0, 0};
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);    
    
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}

#endif // _MDLP_HEADER
