#include "Set.h"

namespace SET
{
	Set::Set(){
		size = 0;
		arr = new int;
	}
	Set::Set(int arr1[], int length){
		
		size = length;
		arr = new int[length];
		int temp = 0;
		for (int i(0); i < length; i++){
			temp = arr1[i];
			arr[i] = temp;
		}
	}
	Set::Set(Set& cp){
		size = cp.size;
		int temp = 0;
		for(int i(0); i < size; i++){
			temp = cp.arr[i];
			arr[i] = temp;
		}
	}
	
	bool Set::crossing(const Set& insp){
		bool ret = false;
		for(int i(0); i < size;	i++)
			for(int j(0); j < insp.size; j++)
				if(arr[i] == insp.arr[j]){
					std::cout << arr[i] << std::endl;	
					ret = true;
				}
		return ret;		
	}
	Set Set::collaboration(const Set& coll){
		int result_size = size + coll.size;
		int* mediator = new int[result_size];
		
		for(int i(0); i < size; i++)
			for(int j(0); j < coll.size; j++){
				if (arr[i] < coll.arr[j])
					mediator[i] = arr[i];
				else 
					mediator[j] = coll.arr[j];
			}
			Set result(mediator,result_size);
			delete[] mediator;
			return result;
		/*for(int i(0); i < size; i++)
			for(int j(0); j < coll.size; j++)
				if(arr[i] == coll.arr[j])
					result_size--;
				
		int meiator[result_size];
		for(int i(0); i < size; i++)
			for(int j(0); j < coll.size; j++)
		*/
		
	
	}
		
	std::ostream& operator<<(std::ostream& os, const Set& v) {
		for(int i(0); i < v.size; i++)
			os << v.arr[i] << " ";
		return os;
	}

	Set::~Set(){
		delete[] arr;
	}
}