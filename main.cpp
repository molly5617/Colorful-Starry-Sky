#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAXSTAR 100
struct STAR
{
    int x;
    int y;
    int step;
    int color;
};
STAR star[101];
void InitStar(int i)
{
    star[i].y = rand() % 24;
    star[i].x = 0;
    star[i].step = (rand() % 5000) / 1000.0 + 1;
    star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);
}
void MoveStar(int i)
{
    COORD pos = {(short)star[i].x, (short)star[i].y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, pos);
    cout << ' ';

    star[i].x += star[i].step;
    if (star[i].x > 80)
        InitStar(i);
    pos.X = (short)star[i].x;
    SetConsoleCursorPosition(hConsole, pos);
    int color = star[i].color % 16 + 0.5;
    SetConsoleTextAttribute(hConsole, color);
    cout << '*';
}
int main()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < MAXSTAR; i++)
    {
        InitStar(i);
        star[i].x = rand() % 80;
    }
    while (1)
    {
        for (int i = 0; i < MAXSTAR; i++)
        {
            MoveStar(i);
        }
        Sleep(40);
    }
}