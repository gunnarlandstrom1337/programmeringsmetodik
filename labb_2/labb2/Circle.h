#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(double radius, std::string color);
	double get_area() const override { return radius*radius*pi; }
protected:
	double pi = 3.14159265359;
	double radius;
};

#endif

