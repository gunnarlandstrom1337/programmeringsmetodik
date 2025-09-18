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

	//sort(source, source+size);

}

size_t int_sorted::size() const
{
	return std::distance(buf.begin(), buf.end());
}

void int_sorted::insert(int value)
{
	
	/*
	//* Vibe coding
	//* 
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
	*(j - 1) = value;
	buf = std::move(insertValue); //Läs om move
	
	*/
	int_sorted mergeValue(&value, 1);
	*this = merge(mergeValue);
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
	int_buffer mergedObject(this->size() + merge_with.size());

	const int* i = this->begin();
	const int* j = merge_with.begin();
	//int* k = mergedObject.begin();
	int* m = mergedObject.end();
	for (int* k = mergedObject.begin(); k != m;) {
		if (i == (this->end())) {
			*k = *j;
			k++;
			j++;
			continue;
		}
		else if (j == (merge_with.end())) {
			*k = *i;
			k++;
			i++;
			continue;
		}

		if (*j < *i) {
			*k = *j;
			j++;
		}
		else {
			*k = *i;
			i++;
		}
		k++;
	}

	int_sorted merged(mergedObject.begin(), mergedObject.size());
	return merged;
}


void int_sorted::resize(size_t size) {
	int_buffer new_bufsize(size);
	std::copy(buf.begin(), buf.begin() + buf.size(), new_bufsize.begin());
	buf = std::move(new_bufsize);
}

int_sorted sort(const int* begin, const
	int* end) {
	if (begin == end) return
		int_sorted(nullptr, 0);
	if (begin == end - 1) return
		int_sorted(begin, 1);
	ptrdiff_t half = (end - begin) / 2; //pointer diff type
		const int* mid = begin + half;
	return sort(begin, mid).merge(sort(
		mid, end));
}