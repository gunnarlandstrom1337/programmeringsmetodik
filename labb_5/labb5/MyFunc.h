#ifndef MYFUNC_H
#define MYFUNC_H
#include "Car.h"

struct MyFunc
{
public:
	MyFunc(double value) :speed(value) {}
	double operator()(double value) { return value-speed; }
private:
	double speed;
};
#endif
