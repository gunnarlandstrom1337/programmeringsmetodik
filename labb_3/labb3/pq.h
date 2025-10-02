#ifndef  PQ_H
#define PQ_H
#include <vector>
#include <algorithm>
#include <iostream>
#include "COMP.H"



template < typename T, typename COMP = std::less<> >
class pq {
public:
	pq() :comparison(COMP()) {};
	pq(COMP comp);
	template < typename IT > pq(IT first, IT last, COMP comp = COMP());
	void push(T element);
	T top() const;
	T pop();
	void print() const;
	size_t size() const;


private:
	COMP comparison;
	std::vector<T> priorityQueue;
};

template<typename T, typename COMP>
template<typename IT>
inline pq<T, COMP>::pq(IT first, IT last, COMP comp)
{
	for (IT i = first; i != last; i++) {
		this->priorityQueue.push_back(*first);
	}
	std::sort(priorityQueue.begin(), priorityQueue.back(), comp);
}

#endif