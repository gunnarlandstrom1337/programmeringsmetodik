#include "order.h"
#include "pq.h"
#include <vector>

void buyAndSell(std::string name, std::vector<order>& buys, std::vector<order>& sells);

int main() {

	std::vector<order> buyOrders;
	std::vector<order> sellOrders;

	buyAndSell("Erik Pendel", buyOrders,sellOrders);
	buyAndSell("Joakim von Anka", buyOrders, sellOrders);
	buyAndSell("Jarl Wallenburg", buyOrders, sellOrders);


	return 0;
}


void buyAndSell(std::string name,std::vector<order>& buys, std::vector<order>& sells) {
	
	for (size_t i = 0; i < 7; i++) {
		order temp(rand() % 30 + 15, name);
		buys.push_back(temp);
	}
	for (size_t i = 0; i < 7; i++) {
		order temp(rand() % 30 + 15, name);
		sells.push_back(temp);
	}
}