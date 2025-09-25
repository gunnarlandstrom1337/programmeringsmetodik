#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H
#include "Rectangle.h"
#include <cstdlib>

class Parallelepiped : public Rectangle
{
public:
	Parallelepiped(double length, double width, double height, std::string color);
	double get_area() const override { return 2 * ((length * width) + (width * height) + (length * height)); }
private:
	double height;
};

#endif

