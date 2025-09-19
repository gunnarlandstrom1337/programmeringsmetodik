#ifndef INT_SORTED_H
#define INT_SORTED_H
#include "int_buffer.h"





class int_sorted {
public:
	
	int_sorted(const int* source, size_t size);
	size_t size() const;
	void insert(int value);
	const int* begin() const;
	const int* end() const;
	int_sorted merge(const int_sorted& merge_with) const;
	
	
	friend int_sorted sort(const int* begin, const int* end);
private:
	int_buffer buf;
	int_sorted();
	int_sorted(int value);
	int_sorted(size_t size);
	int_sorted(const int* begin, const int* end);
};

int_sorted sort(const int* begin, const int* end);


#endif
