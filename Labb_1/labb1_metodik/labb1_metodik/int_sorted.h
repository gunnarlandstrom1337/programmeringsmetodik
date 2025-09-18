#ifndef INT_SORTED_H
#define INT_SORTED_H
#include "int_buffer.h"

class int_sorted {
public:
	//int_sorted() = default;
	int_sorted(const int* source, size_t size);
	void resize(size_t size);
	size_t size() const;
	void insert(int value);
	const int* begin() const;
	const int* end() const;
	int_sorted merge(const int_sorted& merge_with) const;
	friend int_sorted sort(const int* begin, const int* end);
private:
	int_buffer buf;
};


#endif
