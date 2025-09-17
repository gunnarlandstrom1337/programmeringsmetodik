#include <iostream>
#include "student.h"
#include "person.h"
#include "teacher.h"

void print_email(const person& p) {
	std::cout << p.get_email() << "\n";

}



struct S1 {




};

struct S2 {
	int i;
	void f();



};

struct S3 {
	int i;
	virtual void f();



};

int main() {

	std::cout << sizeof(S1) << "\n";
	std::cout << sizeof(S2) << "\n";
	std::cout << sizeof(S3) << "\n";



	/*
	person p("Martin", "markjä");
	student s("Laban", "lala2501");
	teacher t("Martin", "markje");
	//print_email(p);
	print_email(p);
	print_email(s);
	print_email(t);
	*/

}