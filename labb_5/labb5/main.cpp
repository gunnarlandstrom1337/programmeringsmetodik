#include "Car.h"
#include "MyPrint.h"
#include "Predicate.h"
#include "MyBinOp.h"
#include "MyUnOp.h"
#include "MyFunc.h"
#include <numeric>
#include <array>
#include <algorithm>
#include <vector>

int main() {
	std::array<Car, 6> myArr = { Car("BMW", 140.35),Car("AUDI", 83.28), Car("AUDI", 179.14), Car("VOLVO", 362.73), Car("KIA", 177.89), Car("Ferrari", 99.99) };
	std::vector<Car>myVec(myArr.begin(), myArr.end());


	/*
	* Tests if Array and Vector are equal at test #4
	Car car1("SKODA", 555);
	myVec.push_back(car1);
	*/

	// #1
	std::cout << "\nTesting #1\n\n";
		MyPrint temp(myVec);

	// #2
	std::cout << "\nTesting #2\n\n";
	auto it1 = std::find_if(myVec.begin(), myVec.end(), Predicate());
	if (it1 == myVec.end()) {

	}
	else {
		Car temp = *it1;
		std::cout << "High speed predicate found!\n";
		MyPrint temp1(temp);
	}


	// #3
	std::cout << "\nTesting #3\n\n";

	auto it2 = std::adjacent_find(myVec.begin(), myVec.end());
	if (it2 != myVec.end()) {
		Car tempCar = *it2;
		std::cout << "Duplicate name found!\n";
		MyPrint temp2(tempCar);
	}


	// #4
	std::cout << "\nTesting #4\n\n";
	if (std::equal(myArr.begin(), myArr.end(), myVec.begin(), myVec.end())) {
		std::cout << "Array and Vector are equal!\n";
	}
	else {
		std::cout << "Array and Vector are not equal!\n";
	}

	// #5
	std::cout << "\nTesting #5\n\n";

	std::vector<Car>::iterator tempIT;
	tempIT = std::search(myVec.begin(), myVec.end(), &myArr.at(3), &myArr.at(4));

	if (tempIT != myVec.end() && tempIT != myVec.begin()) {
		std::cout << "Subsequence found: \n";
		MyPrint tempPrint(*tempIT);
	}

	// #6
	std::cout << "\nTesting #6\n\n";

	double speed = std::accumulate(myVec.begin(), myVec.end(), 0.0, MyBinOp());
	std::cout << "Accumulated speedvalue: " << speed << "\n";

	// #7
	std::cout << "\nTesting #7\n\n";
	std::vector<double> v2(6);
	std::transform(myVec.begin(), myVec.end(), v2.begin(), MyUnOp());
	MyPrint temp3(v2);

	// #8
	std::cout << "\nTesting #8\n\n";
	std::transform(v2.begin(), v2.end(), v2.begin(), MyFunc(speed));
	MyPrint temp4(v2);

	// #9
	std::cout << "\nTesting #9\n\n";
	std::sort(v2.begin(), v2.end());
	MyPrint temp5(v2);

	return 0;
}

