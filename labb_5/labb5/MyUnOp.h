#ifndef MYUNOP_H
#define MYUNOP_H
#include "Car.h"

struct MyUnOp
{
public:
	double operator()(const Car& car) { return car.getCarSpeed(); }
};
#endif
