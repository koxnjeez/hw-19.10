#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND hwnd = GetConsoleWindow(); // дескриптор окна, используемый консолью
	HDC hdc = GetDC(hwnd); // дескриптор холста (поверхность для рисования на окне)

	system("title Real Graphics: Pen and Brush");
	system("mode con cols=100 lines=30");

	int x = 50;
	int y = 50;

	int width = 700;
	int height = width / 2;

	// красный
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);

	Rectangle(hdc, x, y, x + width, y + height);

	DeleteObject(pen);
	DeleteObject(brush);
	
	// зеленый
	pen = CreatePen(PS_SOLID, 1, RGB(0, 116, 43));
	brush = CreateSolidBrush(RGB(0, 116, 43));

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);

	Rectangle(hdc, x + width / 5, y, x + width, y + height / 3);

	DeleteObject(pen);
	DeleteObject(brush);

	// белый
	pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	brush = CreateSolidBrush(RGB(255, 255, 255));

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);

	Rectangle(hdc, x + width / 5, y + height / 3, x + width, y + height / 3 * 2);

	DeleteObject(pen);
	DeleteObject(brush);

	// черный
	pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	brush = CreateSolidBrush(RGB(0, 0, 0));

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);

	Rectangle(hdc, x + width / 5, y + height / 3 * 2, x + width, y + height);

	DeleteObject(pen);
	DeleteObject(brush);

	cout << "PAKISTAN!";

	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 100;
	SetConsoleCursorInfo(h, &cci);

	Sleep(INFINITE);
}