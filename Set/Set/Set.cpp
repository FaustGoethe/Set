#include "Set.h"

namespace SET
{
	Set::Set():set(){};
	Set::Set(int* arr1, int length) :set(arr1, length) {};
	Set::Set(const Set& cp) {
		set.~List();
		set = cp.set;
	}
	Set::Set(const List& vv) {
		set.~List();
		set = vv;
	}
	Set::Set(int left_limit, int right_limit) {
		if (left_limit >= right_limit)
			std::swap(left_limit, right_limit);
		for (int i = left_limit; i <= right_limit; i++) {
			if (i == 0)
				continue;
			set.push(i);
		}
	}

	int Set::_left()const {
		if (set._begin() == NULL)
			throw std::runtime_error("Begin == NULL");
		return set._begin()->value.key;
	}
	int Set::_right()const {
		if (set._end() == NULL)
			throw std::runtime_error("Begin == End == NULL");
		return set._end()->value.key;
	}

	bool Set::crossing(const Set& insp)const {
		bool ret = false;
		size_t length = set.size();

		for (size_t i(1); i <= length; i++)
			for (size_t j(1); j <= insp.set.size(); j++)
				if (set[i].key == insp.set[j].key) {
					std::cout << set[i] << " ";
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
	Set::operator int*() const {
		const int N = set.size();
		int* ret = new int[N];

		for (int i(0); i < N; i++)
			ret[i] = set[i + 1].key;
		return ret;
	}

	int Set::operator[](size_t ratio) {
		return set[ratio].key;
	}
	std::ostream& operator<<(std::ostream& os, const Set& v) {
		for (int i(1); i <= v.set.size(); i++)
			os << v.set[i].key << " ";
		return os;
	}
}