#include "rounded_rectangle.h"
#include <numbers>

Rounded_rectangle::Rounded_rectangle(double length, double width, double radius, std::string color) : Rectangle(length, width, color), radius(radius)
{
}

double Rounded_rectangle::get_area() const
{
	double pi = 3.14159265359;
	return (length * width) - (4 * radius * radius) + (pi * radius * radius);
}
