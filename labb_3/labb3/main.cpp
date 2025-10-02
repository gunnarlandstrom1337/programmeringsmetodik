#include "order.h"
#include "pq.h"

struct compareByPrice {
	bool operator()(const order& lhs, const order rhs) {
		return lhs.getCost() < rhs.getCost();
	}
};

void buyAndSell(std::string name, std::vector<order>& buys, std::vector<order>& sells);
void insertPrio(std::vector<order>& clients, pq<order, compareByPrice>& prioQueue);

int main() {

	std::vector<order> buyOrders;
	std::vector<order> sellOrders;

	buyAndSell("Erik Pendel", buyOrders, sellOrders);
	buyAndSell("Joakim von Anka", buyOrders, sellOrders);
	buyAndSell("Jarl Wallenburg", buyOrders, sellOrders);

	pq<order, compareByPrice> buyers(buyOrders);
	pq<order, compareByPrice> sellers(sellOrders);

	// insertPrio(buyOrders, buyers);
	// insertPrio(sellOrders, sellers);
	
	pq<order, compareByPrice> test(buyOrders.begin(), buyOrders.end());

	std::cout << "Buyers \n";
	buyers.print();

	std::cout << "\n Sellers \n";
	sellers.print();


	std::cout << "\n Testing \n";
	test.print();

	return 0;
}

void insertPrio(std::vector<order>& clients, pq<order, compareByPrice>& prioQueue) {
	for (size_t i = 0; i != clients.size(); i++) {
		prioQueue.push(clients[i]);
	}
}

void buyAndSell(std::string name, std::vector<order>& buys, std::vector<order>& sells) {

	for (size_t i = 0; i < 7; i++) {
		order temp(rand() % 16 + 15, name);
		buys.push_back(temp);
	}
	for (size_t i = 0; i < 7; i++) {
		order temp(rand() % 16 + 15, name);
		sells.push_back(temp);
	}
}

