#include <windows.h>

void setColorTo(int numColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Pentru a colora consola

    switch(numColor)
    {
        case 0: // DEFAULT
            SetConsoleTextAttribute(hConsole,
            FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
            break;
        case 1: // ROSU
            SetConsoleTextAttribute(hConsole,
            FOREGROUND_RED);
            break;
        case 2: // VERDE
            SetConsoleTextAttribute(hConsole,
            FOREGROUND_GREEN);
            break;  
        case 3: // ALBASTRU
            SetConsoleTextAttribute(hConsole,
            FOREGROUND_BLUE);
            break;
        case 4: // GALBEN
            SetConsoleTextAttribute(hConsole,
            FOREGROUND_RED | FOREGROUND_GREEN);
            break;
        case 5: // ROZ
            SetConsoleTextAttribute(hConsole,
            FOREGROUND_RED | FOREGROUND_BLUE);
            break;
        case 6: // CYAN
            SetConsoleTextAttribute(hConsole,
            FOREGROUND_BLUE | FOREGROUND_GREEN );
            break;

    }
}