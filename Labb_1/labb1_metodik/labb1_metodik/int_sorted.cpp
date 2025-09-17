#include "int_sorted.h"

int_sorted::int_sorted(const int* source, size_t size)
{
	resize(size);

	int* k = buf.begin();
	int* j = buf.end();
	for (const int* i = source; k != j; i++) {
		*k = *i;
		k++;
	}
}

size_t int_sorted::size() const
{
	return std::distance(buf.begin(), buf.end());
}

void int_sorted::insert(int value)
{
	int_buffer insertValue(buf.size() + 1);
	std::copy(buf.begin(), buf.end(), insertValue.begin());
	int* i = insertValue.begin();
	int* j = insertValue.end();
	int k = 0;
	while (i != (j - 1)) {
		if (value < *i) {
			k = *(i);
			*(i) = value;
			value = k;
		}
		i++;
	}
	*(j-1) = value;
	buf = std::move(insertValue); //Läs om move
}


const int* int_sorted::begin() const
{
	return buf.begin();
}

const int* int_sorted::end() const
{
	return buf.end();
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const
{
	return *this;
}


void int_sorted::resize(size_t size) {
	int_buffer new_bufsize(size);
	std::copy(buf.begin(), buf.begin() + buf.size(), new_bufsize.begin());
	buf = std::move(new_bufsize);
}