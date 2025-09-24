#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H
#include "Rectangle.h"

class Parallelepiped : public Rectangle
{
public:
	Parallelepiped(double length, double width, double height, std::string color = "");
	double get_area() const override { return length*width*height; }
private:
	double height;
};

#endif

