#include <iostream>
#include <conio.h>
#include "Set.h"


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	Set a;
	Set b(12,16);

	int* arr = a;
	for (int i(0); i < a.size(); i++)
		std::cout << arr[i] << std::endl;
	_getch();
	return 0;
}