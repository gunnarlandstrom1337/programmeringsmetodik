#include "Car.h"
#include "MyPrint.h"
#include "Predicate.h"
#include <array>
#include <algorithm>

bool isEqual(std::vector<Car>& lhs, std::vector<Car>& rhs);

int main() {
	std::array<Car, 10> myArr = { Car("BMW", 140),Car("AUDI", 83), Car("AUDI", 179), Car("VOLVO", 362), Car("KIA", 177) };
	std::vector<Car>myVec(myArr.begin(), myArr.end());

	// #1
	std::cout << "\nTesting #1\n\n";
	MyPrint temp(myVec);

	//temp.print();


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
	if (it2 == myVec.end()) {

	}
	else {
		Car tempCar = *it2;
		std::cout << "Duplicate name found!\n";
		MyPrint temp2(tempCar);

	}

	/*
	// #4
	std::vector<Car> myArrayVec(myArr.begin(), myArr.end());
	if (isEqual(myVec, myArrayVec)) {
		std::cout << "Array and vector are equal.\n";

	}
	else {
		std::cout << "Array and vector are not equal.\n";
	}
	*/

	return 0;
}

bool isEqual(std::vector<Car>& lhs, std::vector<Car>& rhs) {
	std::sort(lhs.begin(), lhs.end());
	std::sort(rhs.begin(), rhs.end());

	for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++) {
		if (lhs[i] == rhs[i]) {
			i++;
		}
		else {
			return false;
		}
	}
	return true;
}



