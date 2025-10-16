#ifndef PREDICATE_H
#define PREDICATE_H
#include "Car.h"
#include "MyPrint.h"

#include <string>

struct Predicate
{
	bool operator()(const Car& car) {
		return car.getCarSpeed() > pred;
	}
private:
	double pred = 150;

};

#endif
