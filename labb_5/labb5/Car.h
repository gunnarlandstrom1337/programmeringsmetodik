#ifndef CAR_H
#define CAR_H

#include <string>


class Car
{
public:
	Car() = delete;
	Car(std::string name, double speed);



	friend bool operator ==(const Car& lhs, const Car& rhs);
private:
	std::string carName;
	double carSpeed;
};




#endif // !CAR_H