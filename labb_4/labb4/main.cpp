#include "MailBox.h"


template <typename T>
void show(const std::vector<T>& obj) {
	for (auto& e : obj) {
		std::cout << e;
	}
}

int main() {

	MailBox box1;
	box1.push(Email("Anders", "2002-02-28", "lab 1"));
	box1.push(Email("Kalle", "2006-03-29", "lab 2"));
	box1.push(Email("Janne", "2002-02-25", "lab 3"));
	box1.push(Email("Martin", "1993-10-08", "lab 4"));
	box1.push(Email("Anders", "2002-02-28", "lab 6"));


	std::cout << "\n------- SORT WHO --------\n\n";
	box1.SortWho();
	show(box1.getMailbox());

	std::cout << "\n------- SORT SUBJECT --------\n\n";

	box1.SortSubject();
	show(box1.getMailbox());

	std::cout << "\n------- SORT DATE --------\n\n";
	

	box1.SortDate();
	show(box1.getMailbox());


}


