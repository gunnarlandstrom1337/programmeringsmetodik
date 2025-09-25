#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape {
public:
	Shape(std::string color);
	virtual double get_area()const = 0;
	std::string get_color();
	virtual ~Shape() = default;
protected:
	std::string color;
};
#endif
