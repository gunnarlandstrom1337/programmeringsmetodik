#include "shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Rounded_rectangle.h"
#include "Parallelepiped.h"
#include "Cylinder.h"
#include <vector>

void get_data(std::vector<Shape> myVec);

int main() {

	Square square(5, "red");
	Rectangle rectangle(5, 5, "green");
	Circle circle(5, "blue");
	Rounded_rectangle(5, 5, "teal");
	Parallelepiped(5, 5, 5, "orange");
	Cylinnder(5, 5, "yellow");



	return;
}



void get_data(std::vector<Shape> myVec) {
	// iterera ¨o ver samtliga objekt i containern .
	// F ¨o r varje objekt :
	// - Skriv ut objektets f ¨a rg och skriv ut arean .
	// Till sist skriver du ut den totala arean av
	samtliga objekt .
}
