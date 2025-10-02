#ifndef CYLINDER_H
#define CYLINDER_H
#include "Circle.h"

class Cylinder : public Circle
{
public:
	Cylinder(double radius, double height, std::string color);
	double get_area() const override { double pi = 3.14159265359;  return (2 * Circle::get_area()) + (2 * pi * radius * height); }
private:
	double height;
};

#endif

