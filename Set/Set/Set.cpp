#include "Set.h"

namespace SET
{
	Set::Set():set(){};
	Set::Set(int* arr1, int length):set(arr1,length) {};
	Set::Set(Set& cp) {
		set.~List();
		set = cp.set;
	}
	Set::Set(const List& vv) {
		set.~List();
		set = vv;
	}
	Set::~Set() 
	{
	}

	bool Set::crossing(const Set& insp)const  {
		bool ret = false;
		size_t length = set.size();

		for (size_t i(1); i <= length; i++)
			for (size_t j(1); j <= insp.set.size(); j++)
				if (set[i].key == insp.set[j].key) {
					std::cout << set[i] << std::endl;
					ret = true;
				}
		return ret;
	}
	Set Set::collaboration(const Set& coll)const {
		int result_size = set.size() + coll.set.size();
		int* mediator = new int[result_size];

		for (int i(0); i < result_size; i++)
			mediator[i] = 0;

		for (size_t i(0); i < set.size(); i++)
			mediator[i] = set[i].key;

		int i(0);
		for (int j(set.size()); j < result_size; j++) {
			mediator[j] = coll.set[i].key;
			i++;
		}

		Set result(mediator, result_size);
		delete[] mediator;
		return result;
	}

	bool Set::operator==(Set& vv)const {
		if (set.size() != vv.set.size())
			return false;

		bool* ret = new bool[set.size()];
		for (size_t i(0); i < set.size(); i++)
			ret[i] = false;

		for (size_t i(1); i <= set.size(); i++)
			for (size_t j(1); j <= set.size(); j++)
				if (set[i].key == vv[j])
					ret[i-1] = true;

		for(size_t i(0); i < set.size(); i++)
			if (ret[i] != true) {
				delete[] ret;
				return false;
			}
		delete[] ret;
		return true;
	}
	
	bool Set::operator>(const Set& vv) const{
		if(std::abs(set.minimum_value())+std::abs(set.maximum_value()) > std::abs(vv.set.minimum_value()) + std::abs(vv.set.maximum_value()))
			return true;
		return false;
	}
	bool Set::operator<(const Set& vv) const {
		if (std::abs(set.minimum_value()) + std::abs(set.maximum_value()) < std::abs(vv.set.minimum_value()) + std::abs(vv.set.maximum_value()))
			return true;
		return false;
	}


	int Set::operator[](size_t ratio) {
		return set[ratio].key;
	}
	std::ostream& operator<<(std::ostream& os, const Set& v) {
		List::list* temp = v.set._begin();
		while (temp != NULL)
		{
			os << temp->value.key << " ";
			temp = temp->next;
		}
		return os;
	}
}