#pragma once
#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

namespace SLL
{
	typedef long double ld;

	class List
	{	
	public:

		struct content
		{
			int key;
			size_t index;

			friend std::ostream& operator<<(std::ostream&, content&);
			inline content& operator=(size_t v){
				key = v;
				return *this;
		}
		};
	    struct list
		{
			content value;
			list* next;
		};
	private:
		list* begin; // ��������� �� ������
		
		void Indexation(); // ���������� ������� �������� ������ �������
		content* Array(); // ������������� ������ � ���� �������
	public:
		List();
		List(const List&);
		List(const int*,const int);
		~List();

		List& push(const size_t); // ������� �������� n �������� � ������
		List& remove(const size_t); // �������� �������� �� ������ �� ��������
		int remove_at_index(const size_t); // �������� �������� �� ������ �� ������� 
		List& push_back(const size_t); // ������� �������� � ����� ������
		List& push_front(const size_t); // ������� �������� � ������ ������
		size_t size() const; // ����������� ������

		double averege()const; // ������� ������������� �������� ������
		int maximum_value()const; // ������������ �������� ������
		int minimum_value()const; // ����������� �������� ������

		void fout(const std::string&) const;
		size_t KeyFind(const size_t); // ����� �� ��������

		inline list* _begin()const{ // ������� ������
			return begin;
		}

		List& key_sort_bubble(); // ���������� ��������� �� ��������
		List& key_sort_reverse_bubble(); // �������� ���������� ��������� �� ��������
		List& index_sort_bubble(); // ���������� ��������� �� �������
		List& index_sort_reverse_bubble(); // �������� ���������� ��������� �� �������

		friend std::ostream& operator<<(std::ostream&, const List&);
		friend std::istream& operator>>(std::istream&, List&);

		List& fin(const std::string&);
		
		content& operator[](size_t);
		content& operator[](const size_t) const;
	};
}
#endif

using namespace SLL;