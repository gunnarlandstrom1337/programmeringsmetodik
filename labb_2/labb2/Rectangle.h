#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(double length, double width, std::string color);
	double get_area() const override { return length * width; }
protected:
	double length;
	double width;
};

#endif

