#ifndef INDEXABLESET_H_
#define INDEXABLESET_H_

#include <functional>
#include <set>
#include <iterator>

namespace indexable_set
{
template <typename T, typename COMPARE=std::less<T>>
struct indexable_set : std::set<T, COMPARE>
{
	using Base=std::set<T>;
	using std::set<T>::set;
	using size_type = typename std::set<T>::size_type;

	T operator[](int const index) {

		unsigned int absolute_index = abs(index);

		if(index < 0) {
			if(absolute_index > this->size()) {
				throw std::out_of_range{"Index out of bounds!"};
			}
		} else {
			if(absolute_index >= this->size()) {
				throw std::out_of_range{"Index out of bounds!"};
			}
		}

		if(index < 0) {
			return *(std::next(this->end(), index));
		} else {
			return *(std::next(this->begin(), index));
		}
	}

	T front() {
		// WTF? "this->operator" ?!?!?
		return this->operator [](0);
	}

	T back() {
		return this->operator [](-1);
	}
};

}



#endif /* INDEXABLESET_H_ */
