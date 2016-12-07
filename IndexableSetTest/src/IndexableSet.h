#ifndef INDEXABLESET_H_
#define INDEXABLESET_H_

#include <functional>
#include <set>

namespace IndexableSet
{
template <typename T, typename COMPARE=std::less<T>>
struct indexableSet : std::set<T, COMPARE>
{
	using std::set<T>::set;
	using size_type=typename std::set<T>::size_type;

};




}



#endif /* INDEXABLESET_H_ */
