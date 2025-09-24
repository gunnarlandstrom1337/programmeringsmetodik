#include "square.h"

Square::Square(double length, std::string color = "") : Shape(color), length(length)
{
}

double Square::get_area() const{
	return length * length;
}