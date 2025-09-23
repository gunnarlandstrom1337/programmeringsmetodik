#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H
#include "rectangle.h"

class Parallelepiped : public Rectangle
{
public:
	Parallelepiped(double length, double width, double height, std::string color = "");
	double getArea() const { return length*width*height; }
private:
	double height;
};

#endif

