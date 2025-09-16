#include "int_buffer.h"

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

	for (auto e : buf) {
		std::cout << e << ", ";
	}

	//print_buffer(buf);

	return buf;
}


int main()
{
	// första (size) konstruktorn anropas, begin och end anropas utan const
	// man kan anropa for (auto e:buf )
	int_buffer buf1 = f(int_buffer(10));


	return 0;
}