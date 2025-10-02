#include "order.h"


order::order(size_t amount, std::string name) :cost(amount), customer(name)
{
}

std::ostream& operator<<(std::ostream& out, const order& order)
{
	std::cout << "Client: " << order.customer << " , Price: " << order.cost << "\n";
	return out;
}
