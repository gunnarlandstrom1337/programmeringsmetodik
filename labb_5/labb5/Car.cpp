#include "Car.h"

Car::Car(std::string name, double speed):carName(name), carSpeed(speed)
{
}



bool operator==(const Car& lhs, const Car& rhs)
{
	return lhs.carName == rhs.carName;
}
