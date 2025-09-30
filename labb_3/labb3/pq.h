#ifndef  PQ_H
#define PQ_H
#include <functional>




template < typename T, typename COMP = std::less>
class pq {
public:
	pq();
	pq(COMP comp);
	template < typename IT > pq(IT first, IT last, COMP comp = COMP());
	void push(T element);
	T top() const;
	T pop();
	bool empty() const;
	size_t size() const;
};


#endif // ! PQ_H
