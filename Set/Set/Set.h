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
		int operator[](size_t) ;

		friend std::ostream& operator<<(std::ostream&, const Set&);
	};

	class bad_ratio
	{
	private:
		std::string bug_description;
		size_t bug_index;
	public:
		bad_ratio(std::string& error_name, size_t error_ratio) :bug_description(error_name), bug_index(error_ratio) {};
		inline std::string& what_name() {
			return bug_description;
		}
		inline size_t what_index() {
			return bug_index;
		}
	};
}
using namespace SET;
#endif