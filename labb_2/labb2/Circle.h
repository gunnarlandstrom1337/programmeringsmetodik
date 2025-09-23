#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(double radius, std::string color = "");
	double getArea() const { return radius*radius*pi; }
protected:
	double pi = 3.141592653;
	double radius;
};

#endif

