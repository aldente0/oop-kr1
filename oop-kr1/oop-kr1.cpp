﻿// oop-kr1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "main.h";

int main()
{
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HWND console_handle = GetConsoleWindow();
    HDC deviceContext = GetDC(console_handle);
    int fillstyle = 4;
    int color = RGB(200, 100, 200);
    
    RandomRect* rect = new RandomRect(0, 0, 400, 400, color, fillstyle);
    RandomRect* ellipse = new RandomRect(500, 0, 900, 400, color, fillstyle);
    OutputerRandomRect* outputerRect = new OutputerRandomRect(rect);
    OutputerRandomEllipse* outputerEllipse = new OutputerRandomEllipse(ellipse);
    while (true) {
        system("cls");
        outputerRect->output(deviceContext);
        outputerEllipse->output(deviceContext);
        Sleep(1000);
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
