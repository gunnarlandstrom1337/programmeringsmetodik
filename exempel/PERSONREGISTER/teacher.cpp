#include "teacher.h"

teacher::teacher(std::string name, std::string login) :person(name, login)
{

}

std::string teacher::get_email() const {
	return person::get_email();
}
