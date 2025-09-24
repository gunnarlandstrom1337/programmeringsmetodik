#include "lab_assistant.h"

lab_assistant::lab_assistant(const std::string& name, const std::string& login) :person(name, login), student(name, login), teacher(name, login)
{
}

std::string lab_assistant::get_email() const
{
	return teacher::get_email();
}

