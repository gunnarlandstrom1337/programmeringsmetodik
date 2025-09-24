#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square : public Shape
{
public:
	Square(double length, std::string color = "");
	double get_area() const override;
protected:
	double length;
};

#endif
