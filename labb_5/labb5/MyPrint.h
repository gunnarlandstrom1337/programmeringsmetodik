#ifndef MYPRINT_H
#define MYPRINT_H
#include <iostream>
#include "Car.h"
#include <vector>

class MyPrint
{
public:
	MyPrint();
	MyPrint(const Car& car);
	
	MyPrint(const std::vector<Car>& car);
	MyPrint(const std::vector<double>& doubleVec);
	void printCar(const std::vector<Car>& cars);
	friend std::ostream& operator<<(std::ostream&, const Car& car);
};


#endif

