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
	using std::set<T>::set;
	using size_type = typename std::set<T>::size_type;

	T operator[](int index)
	{
		if(index < 0)
		{
			return std::next(this->end(), index);
		}else
		{
			return std::next(this->begin(), index);
		}

	}

};




}



#endif /* INDEXABLESET_H_ */
