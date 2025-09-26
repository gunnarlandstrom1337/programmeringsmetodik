#include <vector>
#include <iostream>
#include <iterator>


template<typename ForwardIt>
ForwardIt find_min(ForwardIt first, ForwardIt last) {
	ForwardIt min = first;

	while (first != last) {
		if (*first < *min) {
			min = first;
		}

		first++;
	}
	return min;

}


template<typename IT>
void selection_sort(IT first, IT last) {

	for (; first != last; first++) {
		auto min = find_min(first, last);
		std::iter_swap(min, first);
	}
}

struct email {
	std::string name;
	std::string email;

};


int main() {

	std::vector<email> v = { {"Martin", "m@yahoo.com"}, {"Nitram", "n@geocities.com"}, {"Laban", "l@lycos.com"} };

	//std::vector<int> v = { 7,3,4,5 };
	auto out = std::ostream_iterator<int>(std::cout, ", ");
	selection_sort(v.begin(), v.end());
	std::copy(v.begin(), v.end(), out);

	for (auto e : v) {
		std::cout << e << "\n";
	}
}