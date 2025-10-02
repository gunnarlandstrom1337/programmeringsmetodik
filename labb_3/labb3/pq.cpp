#include "pq.h"
/*
template<typename T, typename COMP>
pq<T, COMP>::pq(COMP comp) :compare(comp)
{
}

template<typename T, typename COMP>
inline T pq<T, COMP>::top() const
{
	return priorityQueue.front();
}


template<typename T, typename COMP>
inline T pq<T, COMP>::pop()
{
	T temp = priorityQueue.back();
	priorityQueue.pop_back();
	return temp;
}

template<typename T, typename COMP>
inline size_t pq<T, COMP>::size() const
{
	return priorityQueue.size();
}


template<typename T, typename COMP>
inline void pq<T, COMP>::push(T element)
{
	priorityQueue.push_back(element);
	std::sort(priorityQueue.begin(), priorityQueue.end(), compare);
}

template<typename T, typename COMP>
inline void pq<T, COMP>::print() const
{
	for (auto e : priorityQueue) {
		std::cout << e;
	}

}

template<typename T, typename COMP>
template<typename IT>
inline pq<T, COMP>::pq(IT first, IT last, COMP comp)
{
	for (IT i = first; i != last; i++) {
		this->priorityQueue.push_back(*first);
	}
	std::sort(priorityQueue.begin(), priorityQueue.back(), comp);
}
*/