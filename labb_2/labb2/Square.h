#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

class Square : public Shape
{
public:
	Square(double length, std::string color);
	double get_area() const override { return length * length; };
protected:
	double length;
};
#endif
