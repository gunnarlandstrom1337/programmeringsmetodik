#include "MyPrint.h"

std::ostream& operator <<(std::ostream& rhs, const Car& car)
{
	std::cout << "Car name: " << car.getCarName() << " Car speed: " << car.getCarSpeed() << "\n";
	return rhs;
}

MyPrint::MyPrint(const std::vector<Car>& car)
{
	printCar(car);
}

MyPrint::MyPrint(const Car& car)
{
	std::cout << "Car name: " << car.getCarName() << " Car speed: " << car.getCarSpeed() << "\n";
}

/*
MyPrint::MyPrint(std::vector<Car>::iterator& it)
{
}
*/

MyPrint::MyPrint()
{
}

void MyPrint::printCar(const std::vector<Car>& cars) {
	for (auto& e : cars) {
		std::cout << e;
	}
}

MyPrint::MyPrint(const std::vector<double>& doubleVec) {
	for (auto& e : doubleVec) {
		std::cout << "Value: " << e << "\n";
	}
}

