#ifndef  PQ_H
#define PQ_H
#include <vector>
#include <algorithm>
#include <iostream>
#include "order.h"


template < typename T, typename COMP = std::less<T> >
class pq {
public:
	pq() = default;
	pq(COMP comp) :compare(comp) {};

	pq(const std::vector<order>& orders)
	{
		for (size_t i = 0; i != orders.size(); i++) {
			this->push(orders[i]);
		}
	};

	template <typename IT> pq(IT first, IT last, COMP comp = COMP()) {
		for (IT i = first; i != last; i++) {
			this->priorityQueue.push_back(*i);
		}
		std::sort(priorityQueue.begin(), priorityQueue.end(), comp);
	};

	void push(T element) {
		priorityQueue.push_back(element);
		std::sort(priorityQueue.begin(), priorityQueue.end(), compare);
	};

	T top() const { return priorityQueue.front(); };

	T pop() {
		T temp = priorityQueue.back();
		priorityQueue.pop_back();
		return temp;
	};

	void print() const
	{
		for (auto& e : priorityQueue) {
			std::cout << e;
		}
	};


	size_t size() const
	{
		return priorityQueue.size();
	};



private:
	COMP compare;
	std::vector<T> priorityQueue;

};


#endif