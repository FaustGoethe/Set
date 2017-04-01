#include <iostream>
#include <conio.h>
#include "Set.h"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	int ar[3] = { 12,5,4 };
	Set a(ar, 3);
	std::cout << a;
	_getch();
	return 0;
}