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
	using std::set<T, COMPARE>::set;
	using size_type = typename std::set<T>::size_type;
	using constref = T const &;

	constref operator[](int index) const {

		if(index < 0) {
			index = this->size() + index;
		}
		if(index <0 || static_cast<size_type>(index) >= this->size()) {
			throw std::out_of_range{"Index out of bounds!"};
		}
			return *(std::next(this->begin(), index));
	}

	constref front() const {
		return (*this)[0];
	}

	constref back() const {
		return (*this)[-1];
	}
};

}



#endif /* INDEXABLESET_H_ */
