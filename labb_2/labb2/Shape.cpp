#include "shape.h"
#include "Rectangle.h"

Shape::Shape(std::string color) : color(color)
{
}

double Shape::get_area()
{
}

std::string Shape::get_color()
{
	return color;
}
