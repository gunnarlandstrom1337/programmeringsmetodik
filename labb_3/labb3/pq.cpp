#include "pq.h"

template<typename T, typename COMP>
pq<T, COMP>::pq(COMP comp) :comparison(comp)
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
}

template<typename T, typename COMP>
inline void pq<T, COMP>::print() const
{
	for (auto e : priorityQueue) {
		std::cout << e;
	}

}
