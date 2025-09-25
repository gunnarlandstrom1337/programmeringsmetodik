#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Rounded_rectangle.h"
#include "Parallelepiped.h"
#include "Cylinder.h"
#include <vector>
#include <iostream>

void get_data(const std::vector<std::unique_ptr<Shape>>& vec);

int main() {

	std::vector<std::unique_ptr<Shape>> myVec;

	myVec.push_back(std::make_unique<Square>(5, "Red"));
	myVec.push_back(std::make_unique<Rectangle>(6, 4, "Green"));
	myVec.push_back(std::make_unique<Circle>(5, "Blue"));
	myVec.push_back(std::make_unique<Rounded_rectangle>(5, 5, 2, "Teal"));
	myVec.push_back(std::make_unique<Cylinder>(6, 9, "Yellow"));
	myVec.push_back(std::make_unique<Parallelepiped>(7, 3, 3, "Orange"));

	get_data(myVec);

	return 0;
}



void get_data(const std::vector<std::unique_ptr<Shape>>& myVec) {
	// iterera ¨o ver samtliga objekt i containern .
	// F ¨o r varje objekt :
	// - Skriv ut objektets f ¨a rg och skriv ut arean .
	// Till sist skriver du ut den totala arean av
	//samtliga objekt .

	double areaTotal = 0;

	for (auto& e : myVec) {
		std::cout << "Area: " << e->get_area() << "\n";
		std::cout << "Color: " << e->get_color() << "\n\n";
		areaTotal += e->get_area();
	}
	std::cout << "Total area of all objects: " << areaTotal;
}
