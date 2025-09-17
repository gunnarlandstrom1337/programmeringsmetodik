#include "int_buffer.h"

int_buffer::~int_buffer() {
	delete[]first;
}

// Denna konstruktorn anropas av första funktionen
int_buffer::int_buffer(size_t size) :first(new int[size]), last(first + size) {

}

int_buffer::int_buffer(const int* source, size_t size) :int_buffer(size) {
	std::copy(source, source + size, first);
}

// copy construct
int_buffer::int_buffer(const int_buffer& rhs) :int_buffer(rhs.begin(), rhs.size()) {

}

// move construct
int_buffer::int_buffer(int_buffer&& rhs) noexcept :first(nullptr), last(nullptr) {
	swap(rhs);
}

// copy assign
int_buffer& int_buffer::operator =(const int_buffer& rhs) {
	int_buffer cpy(rhs);
	swap(cpy);
	return *this;
}

// move assign
int_buffer& int_buffer::operator=(int_buffer&& rhs) noexcept {
	swap(rhs);
	return *this;
}

int& int_buffer::operator [](size_t index) {
	return first[index];
}

size_t int_buffer::size() const {
	return std::distance(first, last);
}

int* int_buffer::begin() {
	return first;
}

int* int_buffer::end() {
	return last;
}

const int* int_buffer::begin() const {
	return first;
}


const int* int_buffer::end() const {
	return last;
}

void int_buffer::swap(int_buffer& rhs) {
	std::swap(rhs.first, first);
	std::swap(rhs.last, last);
}