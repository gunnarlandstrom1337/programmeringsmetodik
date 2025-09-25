#include "Shape.h"

Shape::Shape(std::string color) : color(color)
{
}


std::string Shape::get_color()
{
	return color;
}
