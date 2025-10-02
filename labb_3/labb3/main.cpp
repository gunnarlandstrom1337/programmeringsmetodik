#include "order.h"
#include "pq.cpp"
#include <vector>
#include <iostream>

void buyAndSell(std::string name, std::vector<order>& buys, std::vector<order>& sells);
void fillPrioqueue(std::vector<order>& clients, pq<order>& prioQueue);



int main() {

	std::vector<order> buyOrders;
	std::vector<order> sellOrders;

	buyAndSell("Erik Pendel", buyOrders, sellOrders);
	buyAndSell("Joakim von Anka", buyOrders, sellOrders);
	buyAndSell("Jarl Wallenburg", buyOrders, sellOrders);

	//pq<order> test(buyOrders.begin(), buyOrders.end());
	pq<order> buyers;
	pq<order> sellers;

	fillPrioqueue(buyOrders, buyers);
	fillPrioqueue(sellOrders, sellers);

	std::cout << "Buyers \n";
	buyers.print();

	std::cout << "\n Sellers \n";
	sellers.print();

	return 0;
}

struct comp {
public:
	bool operator()(const order& lhs, const order rhs) {
		return lhs.getCost() < rhs.getCost();
	}
};

void fillPrioqueue(std::vector<order>& clients, pq<order>& prioQueue) {
	std::sort(clients.begin(), clients.end(), comp());
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

