#include "cylinder.h"

Cylinder::Cylinder(double radius, double height, std::string color): Circle(radius, color), h(height)
{


}

double Cylinder::getVolume(double radius, double height, double pi)
{
	return radius * radius * pi * height;
}
