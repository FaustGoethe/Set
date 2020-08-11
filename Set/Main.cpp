#include <iostream>
#include <conio.h>
#include "Set.h"


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");

	Set a(14,45);
	Set b(29,-26);
	Set c(-26, 29);
	//Set d(a + b + c);
	
	std::cout << c+b+a;
	_getch();
	return 0;
}