#include "rounded_rectangle.h"
#include <numbers>
#include "Circle.h"
#include "Square.h"

Rounded_rectangle::Rounded_rectangle(double length, double width, double radius, std::string color) : Rectangle(length, width, color), radius(radius)
{
}

double Rounded_rectangle::get_area() const
{
	Circle tempCircle(radius, "");
	Square tempSquare(radius, "");
	double pi = 3.14159265359;

	return Rectangle::get_area() - 4 * tempSquare.get_area() + tempCircle.get_area();
}
