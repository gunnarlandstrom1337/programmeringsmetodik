#include "int_buffer.h"
#include "int_sorted.h"
#include <chrono>

void selectionSort(int_buffer& buffer);

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

	/*
	int_sorted sortedbuf(buf2.begin(), buf2.size());
	int_sorted sortedbuf2(buf1.begin(), buf1.size());
	*/

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
	std::cout << "\n\nThis is scramble buffer *TIME*:  \n";
	auto start = std::chrono::high_resolution_clock::now();

	int_buffer scrambleTest(400000);
	int_buffer scrambleSelectionSort(400000);
	/*
	for (int* i = scrambleTest.begin(); i != scrambleTest.end(); i++) {
		*i = rand() % 1000;
	}
	auto stop1 = std::chrono::high_resolution_clock::now();

	/*
	for (const int* i = scrambleTest.begin(); i !=
		scrambleTest.end(); i++) {
		std::cout << *i << ", ";
	}


	int_sorted sortedTest(scrambleTest.begin(), scrambleTest.size());
	auto stop2 = std::chrono::high_resolution_clock::now();
	*/

	for (int* i = scrambleSelectionSort.begin(); i != scrambleSelectionSort.end(); i++) {
		*i = rand() % 1000;
	}

	selectionSort(scrambleSelectionSort);
	auto stop3 = std::chrono::high_resolution_clock::now();

	/*
	for (const int* i = scrambleSelectionSort.begin(); i !=
		scrambleSelectionSort.end(); i++) {
		std::cout << *i << ", ";
	}
	*/

	/*
	std::cout << "\n\nTHIS IS SORTED BUFFER: \n";
	for (const int* i = sortedTest.begin(); i !=
		sortedTest.end(); i++) {
		std::cout << *i << ", ";
	}
	*/
	//auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start);
	//auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop2 - start);
	auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(stop3 - start);
	
	
	//std::cout << "Times are: unsorted buffer 400k elements: " << duration1.count() << "ms\n";
	//std::cout << "Times are: sorted buffer 400k elements: " << duration2.count() << "ms\n";
	std::cout << "Selection sort*** Times are: sorted buffer 400k elements: " << duration3.count() << "ms\n";


	return 0;
}

// 400k element 615,835ms
void selectionSort(int_buffer& buffer) {
	int n = buffer.size();

	for (int i = 0; i < n; ++i) {

		// Assume the current position holds
		// the minimum element
		int min_idx = i;

		// Iterate through the unsorted portion
		// to find the actual minimum
		for (int j = i + 1; j < n; ++j) {
			if (buffer[j] < buffer[min_idx]) {

				// Update min_idx if a smaller
				// element is found
				min_idx = j;
			}
		}

		// Move minimum element to its
		// correct position
		std::swap(buffer[i], buffer[min_idx]);
	}
}