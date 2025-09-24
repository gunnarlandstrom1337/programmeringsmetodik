#ifndef ROUNDED_RECTANGLE_H
#define ROUNDED_RECTANGLE_H
#include "rectangle.h"

class Rounded_rectangle : public Rectangle
{
public:
	Rounded_rectangle(double length, double width, std::string color = "");
	double get_area() const override { return; }
};

#endif

