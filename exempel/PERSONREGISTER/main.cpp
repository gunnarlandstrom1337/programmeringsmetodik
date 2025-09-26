#include <iostream>
#include "student.h"
#include "person.h"
#include "teacher.h"
#include "lab_assistant.h"




/*
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

struct S4 :S3 {
	void f() override;
};
*/

/*
const int f() {
}
*/
/*
std::pair<std::string, int> f() {
	return { "Hello",-1 };
}
//Structured bindingn
auto [txt:string, val:int] = f();
*/

void print_email(const person& p) {
	std::cout << p.get_email() << "\n";

}

void print_email_student(const student& p) {
	std::cout << p.get_email() << "\n";

}

bool is_teacher(const person& p) {
	try {
		auto& test = dynamic_cast<const teacher&>(p);
		return true;
	}
	catch (std::exception& e){}
	return false;
}

int main() {
	/*
	std::cout << sizeof(S1) << "\n";
	std::cout << sizeof(S2) << "\n";
	std::cout << sizeof(S3) << "\n";
	*/

	student s("studde", "stud2508");
	teacher t("Martin", "markeje");
	//lab_assistant la("Laban", "labben");
	//print_email(s);
	//print_email(t);
	//print_email_student(la);
	//print_email(la);
	if (is_teacher(s)) {
		std::cout << s.get_name() << "is a teacher";
	}
	else {
		std::cout << s.get_name() << "is a student";
	}


}