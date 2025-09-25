#ifndef CYLINDER_H
#define CYLINDER_H
#include "Circle.h"

class Cylinder : public Circle
{
public:
	Cylinder(double radius, double height, std::string color);
	double get_area() const override { return (2 * pi * radius * radius) + (2 * pi * radius * height); }
private:
	double height;
};

#endif

