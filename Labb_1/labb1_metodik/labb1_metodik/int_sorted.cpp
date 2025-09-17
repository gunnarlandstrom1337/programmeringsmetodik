#include "int_sorted.h"

int_sorted::int_sorted(const int* source, size_t size)
{
}

size_t int_sorted::size() const
{
	return sizeOfContainer;
}

void int_sorted::insert(int value)
{
	push_back(value);
}

void int_sorted::push_back(int value) {
	*last = value;
	last++;
	sizeOfContainer++;
}

const int* int_sorted::begin() const
{
	return first;
}

const int* int_sorted::end() const
{
	return last;
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const
{
	return *this;
}
