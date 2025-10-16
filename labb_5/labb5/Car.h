#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>


class Car
{
public:
	Car() = default;
	Car(std::string name, double speed);
	std::string getCarName() const { return carName; }
	double getCarSpeed() const { return carSpeed; }

	
	friend bool operator ==(const Car& lhs, const Car& rhs);
private:
	std::string carName;
	double carSpeed;
};




#endif // !CAR_H