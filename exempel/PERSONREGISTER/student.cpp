#include "student.h"
#include <string>

student::student(std::string name, std::string login): name(name), login(login)
{



}

std::string student::get_email() const {
	return get_login() + "@student.miun.se";
}
