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


	std::cout << "\n\nThis is scramble buffer *TIME*:  \n";

	int_buffer bufTest(100000);
	int_buffer scrambleSelectionSort(100000);
	for (int* i = bufTest.begin(); i != bufTest.end(); i++) {
		*i = rand() % 1000;
	}
	for (int* i = scrambleSelectionSort.begin(); i != scrambleSelectionSort.end(); i++) {
		*i = rand() % 1000;
	}

	/*
	for (auto e : bufTest) {
		std::cout << e << ", ";
	}
	*/
	auto start = std::chrono::high_resolution_clock::now();
	int_sorted sortedTest(bufTest.begin(), bufTest.size());

	/*
	for (auto e : sortedTest) {
		std::cout << e << ", ";
	}
	*/

	auto stop1 = std::chrono::high_resolution_clock::now();

	auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start);
	auto start2 = std::chrono::high_resolution_clock::now();
	selectionSort(scrambleSelectionSort);
	auto stop2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop2 - start2);


	std::cout << "Times are: unsorted buffer 100k elements: " << duration1.count() << "ms\n";
	std::cout << "Times are: unsorted buffer 100k elements with selection sort: " << duration2.count() << "ms\n";


	return 0;
}

// 400k element 615,835ms
void selectionSort(int_buffer& buffer) {
	int n = buffer.size();

	for (int i = 0; i < n; ++i) {

		int min_idx = i;

		for (int j = i + 1; j < n; ++j) {
			if (buffer[j] < buffer[min_idx]) {
				min_idx = j;
			}
		}
		std::swap(buffer[i], buffer[min_idx]);
	}
}