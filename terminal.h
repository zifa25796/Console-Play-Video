#pragma once
#include <winsock.h>
#include <windows.h>

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void text_colour(int serial) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), serial);
}

void hidecursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void showcursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 1 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int fixNumber(int num) {
	if (0 <= num && num <= 64) {
		return 0;
	}
	else if (64 <= num && num <= 160) {
		return 128;
	}
	else if (160 <= num && num <= 224) {
		return 192;
	}
	else if (224 <= num && num <= 255) {
		return 255;
	}
}

int RGB2ConsoleColor(int R, int G, int B) {
	static int consoleColor[46][4] = {
		{000, 000, 000, 256},
		{000, 000, 128, 273},
		{000, 128, 000, 34},
		{000, 128, 128, 51},
		{128, 000, 000, 68},
		{128, 000, 128, 102},//85
		{128, 128, 000, 102},
		{192, 192, 192, 119},
		{128, 128, 128, 136},
		{000, 000, 255, 153},
		{000, 255, 000, 170},
		{000, 255, 255, 187},
		{255, 000, 000, 204},
		{255, 000, 255, 85},
		{255, 255, 000, 238},
		{255, 255, 255, 255},
		{192, 128, 128, 238},
		{192, 128, 192, 119},
		{255, 128, 192, 238},//221
		{192, 000, 128, 204},
		{255, 192, 192, 136},
		{255, 128, 255, 119},
		{255, 192, 255, 119},
		{192, 255, 192, 170},
		{128, 192, 192, 51},
		{128, 192, 128, 34},
		{192, 000, 192, 85},//221
		{192, 128, 000, 68},
		{192, 000, 000, 204},
		{255, 128, 128, 204},
		{192, 192, 128, 102},
		{255, 000, 128, 85},//221
		{255, 000, 192, 85},//221
		{255, 255, 192, 255},
		{255, 192, 128, 238},
		{128, 128, 192, 136},
		{255, 128, 000, 238},
		{128, 000, 192, 273},
		{192, 255, 255, 187},
		{128, 255, 192, 170},
		{000, 192, 128, 34},
		{255, 255, 128, 238},
		{192, 192, 255, 255},
		{255, 192, 000, 238},
		{128, 192, 255, 51},
		{192, 192, 000, 238}
	};

	/*int r = R, g = G, b = B;*/

	R = fixNumber(R);
	G = fixNumber(G);
	B = fixNumber(B);

	/*if (128 == R && 0 == G && 128 == B) {
		int a = 0;
		a++;
	}*/

	for (int i = 0; i < 46; i++) {
		if (consoleColor[i][0] == R && consoleColor[i][1] == G && consoleColor[i][2] == B) {
			return consoleColor[i][3];
		}
	}
	return 0;
}

