#include "buffer.h"


buffer::buffer(int* src, size_t sz) :buffer(sz) {

	std::copy(src, src + sz, first);
}

void buffer::swap(buffer& src) {
	std::swap(src.first, first);
	std::swap(src.last, last);
}

buffer::~buffer() {
	delete[] first;
}

buffer::buffer() {

}

buffer& buffer::operator=(buffer&& rhs) {
	swap(rhs);
	return *this;
}

int& buffer::front() {

}

int& buffer::back() {

}
int buffer::front() const {

}
int buffer::back() const {

}

/* AVANCERAD LÖSNING
buffer& buffer::operator=(buffer rhs) {
	swap(rhs);
	return *this;
}
*/



// COPY AND SWAP-IDIOM
buffer& buffer::operator=(const buffer& rhs)
{
	buffer cpy(rhs);
	swap(cpy);
	return *this;
}

