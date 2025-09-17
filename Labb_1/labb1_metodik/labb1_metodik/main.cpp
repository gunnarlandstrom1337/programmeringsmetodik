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

	std::cout << "\n" << "SORTED STARTS HERE" << "\n" << "\n";
	
	int_sorted sortedbuf(buf2.begin(), buf2.size());


	for (int i = 0; i < 400; i++) {
		sortedbuf.insert(rand() % 1000);
	}
	sortedbuf.insert(32);


	for (const int* i = sortedbuf.begin(); i !=
		sortedbuf.end(); i++) {
		std::cout << *i << ", ";
	}


	return 0;
}