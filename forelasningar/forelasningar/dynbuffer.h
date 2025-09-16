#ifndef DYNBUFFER_H
#define DYNBUFFER_H
#include "buffer.h"


class dynbuffer {

public:
	dynbuffer(buffer src);
	int* begin();
	const int* begin() const;
	int* end();
	const int* end() const;
	size_t size() const;
	size_t capacity() const;

	void push_back(int e);
	int& front();
	int& back();


private:
	size_t sz;
	buffer data;

};



#endif
