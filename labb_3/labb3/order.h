#ifndef  ORDER_H
#define ORDER_H
#include <string>

struct order
{
public:
	order(size_t amount, std::string name);
private:
	std::string customer;
	size_t cost;
};

#endif