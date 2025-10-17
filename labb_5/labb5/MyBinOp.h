#ifndef MYBINOP_H
#define MYBINOP_H
#include "Car.h"

struct MyBinOp
{
public:
	double operator()(double lhs, Car& rhs) { return lhs + rhs.getCarSpeed(); }
};
#endif

