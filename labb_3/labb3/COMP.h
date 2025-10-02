#ifndef COMP_H
#define COMP_H

template < typename T>
struct COMP
{
public:
	bool compare(T& a, T& b) { return a < b ? b : a; }
};




#endif 
