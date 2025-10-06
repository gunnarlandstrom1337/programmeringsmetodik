#ifndef  ORDER_H
#define ORDER_H
#include <string>
#include <iostream>

struct order
{
public:
	order(size_t amount, std::string name);
	size_t getCost() const { return cost; }
	std::string getName() const { return customer; }
	friend std::ostream& operator <<(std::ostream& out, const order& order);

private:
	std::string customer;
	size_t cost;
};

#endif