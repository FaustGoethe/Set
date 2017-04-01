#pragma once
#ifndef _SET_H
#define _SET_H
#include <iostream>

namespace SET
{
	class Set
	{
	private:
		int* arr; // Множество целых чисел
		int size; // Размер множества
	public:
		explicit Set();
		explicit Set(int*,int);
		explicit Set(const Set&);
		
		bool crossing(const Set&); // Пересечение множеств
		Set collaboration(const Set&);
		
		friend std::ostream& operator<<(std::ostream&, const Set&);
		~Set();
	};
}
using namespace SET;
#endif