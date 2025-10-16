#ifndef MYPRINT_H
#define MYPRINT_H
#include <iostream>
#include "Car.h"
#include <vector>

class MyPrint
{
public:
	MyPrint();
	MyPrint(const std::vector<Car>& car);
	MyPrint(const Car& car);
	void printCar(const std::vector<Car>& cars);
	void print();
	friend std::ostream& operator<<(std::ostream&, const Car& car);
private:
	std::vector<Car> savedVec;
};


#endif

