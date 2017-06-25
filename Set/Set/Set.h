#pragma once
#ifndef _SET_H
#define _SET_H
#include <iostream>
#include <string> 
#include "List.h"
namespace SET
{
	class Set
	{
	private:
		List set; // Множество целых чисел

	public:
		Set();
		Set(int*,int);
		Set(const List&);
		Set(const Set&);
		Set(int, int);
		
		int _left()const; // Левая граница множества
		int _right()const; // Правая граница множества

		inline size_t size() const {
			return set.size();
		} // Размер множества

		bool crossing(const Set&) const; // Пересечение множеств
		
		bool operator==(Set&) const;
		Set& operator+(const Set&); // Объединение множеств

		operator int*() const;
		int operator[](int) const;
		int operator[](int);
		friend std::ostream& operator<<(std::ostream&, const Set&);
	};

}
using namespace SET;
#endif