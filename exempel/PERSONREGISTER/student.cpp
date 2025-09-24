#include "student.h"

student::student(std::string name, std::string login) :person(name, login)
{

}

std::string student::get_email() const {
	return get_login() + "@student.miun.se";
}
