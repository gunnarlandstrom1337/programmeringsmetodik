#ifndef CYLINDER_H
#define CYLINDER_H
#include "circle.h"

class Cylinder : public Circle
{
public:
	Cylinder(double radius,double height, std::string color);
	double getVolume() const { return radius * radius * pi * height; }
private:
	double height;
};

#endif

