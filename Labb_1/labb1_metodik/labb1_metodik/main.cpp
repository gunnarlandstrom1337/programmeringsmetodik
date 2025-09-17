#include "int_buffer.h"
#include "int_sorted.h"

void print_buffer(int_buffer buf) {
	for (const int* i = buf.begin(); i !=
		buf.end(); i++) {
		std::cout << *i << ", ";

	}
}

int_buffer f(int_buffer buf) {

	int j = 1;
	for (int* i = buf.begin(); i != buf.end();
		i++) {
		*i = j;
		j++;
	}

	for (const int* i = buf.begin(); i !=
		buf.end(); i++) {
		std::cout << *i << ", ";

	}

	std::cout << "\n";

	/*
	for (auto e : buf) {
		std::cout << e << ", ";
	}
	*/

	//print_buffer(buf);

	return buf;
}


int main()
{
	// första (size) konstruktorn anropas, begin och end anropas utan const
	// man kan for-range syntax
	int_buffer buf1 = f(int_buffer(10));

	int_buffer buf2 = f(buf1);
	buf2 = f(buf1);


	return 0;
}