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
	int_sorted sortedbuf2(buf1.begin(), buf1.size());

	/*
	for (int i = 0; i < 500; i++) {
		sortedbuf.insert(rand() % 10000);
	}
	//sortedbuf.insert(32);

	std::cout << "\n\nTHIS IS 1ST SORTED BUFFER: \n";
	for (const int* i = sortedbuf.begin(); i !=
		sortedbuf.end(); i++) {
		std::cout << *i << ", ";
	}


	*/
	int_buffer buf3(0);
	int_sorted sortedbuf3(buf3.begin(), buf3.size());
	for (int i = 0; i != 40000; i++) {
		sortedbuf3.insert(rand() % 1000);
	}

	/*
	std::cout << "\n\nTHIS IS 2ND SORTED BUFFER: \n";
	for (const int* i = sortedbuf2.begin(); i !=
		sortedbuf2.end(); i++) {
		std::cout << *i << ", ";
	}

	sortedbuf = sortedbuf.merge(sortedbuf2);

	int_sorted sortedbuf3;
	std::cout << "\n\nTHIS IS 3RD SORTED BUFFER: \n";
	for (const int* i = sortedbuf3.begin(); i !=
		sortedbuf3.end(); i++) {
		std::cout << *i << ", ";
	}

	sortedbuf = sortedbuf.merge(sortedbuf3);


	std::cout << "\n\nTHIS IS MERGED BUFFER: \n";
	for (const int* i = sortedbuf.begin(); i !=
		sortedbuf.end(); i++) {
		std::cout << *i << ", ";
	}

	int_buffer scrambleBuffer(4000);

	std::cout << "\n\nTHIS IS SCRAMBLED BUFFER: \n";
	for (int* i = scrambleBuffer.begin(); i != scrambleBuffer.end(); i++) {
		int k = rand() % 10000;
			*i = k;
	}


	int_sorted sortedBuffer(scrambleBuffer.begin(), scrambleBuffer.size());

	for (const int* i = sortedBuffer.begin(); i !=
		sortedBuffer.end(); i++) {
		std::cout << *i << ", ";
	}
	*/


	return 0;
}