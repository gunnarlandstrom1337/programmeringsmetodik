#ifndef BUFFER_H
#define BUFFE_H
#include <iostream>
#include <iterator>
class buffer {



public:
	buffer() = delete;
	explicit buffer(size_t size);
	buffer(const buffer& src);
	buffer(int* source, size_t size);
	buffer(buffer&& src) noexcept;
	~buffer();

	buffer& operator =(const buffer& rhs);
	buffer& operator =(buffer&& rhs);
	buffer& operator=(buffer rhs);

	int& operator[](size_t idx);
	int operator[](size_t idx) const;

	void swap(buffer& src);
	int* begin();
	int* end();
	int* begin() const;
	int* end() const;
	size_t size() const;

	
	int& front();
	int& back();

	int front() const;
	int back() const;


private:
	int* first;
	int* last;

};






#endif
