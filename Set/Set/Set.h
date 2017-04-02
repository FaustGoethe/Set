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
		Set(Set&);
		~Set();
		
		bool crossing(const Set&) const; // Пересечение множеств
		Set collaboration(const Set&) const; // Объединение множеств
		
		bool operator==(Set&)const;
		int operator[](size_t);
		bool operator>(const Set&)const;
		bool operator<(const Set&)const;

		friend std::ostream& operator<<(std::ostream&, const Set&);
	};

}
using namespace SET;
#endif