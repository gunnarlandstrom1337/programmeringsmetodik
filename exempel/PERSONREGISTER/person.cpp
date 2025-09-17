#include "person.h"

person::person(std::string name, std::string login): name(name), login(login)
{

}

std::string person::get_email() const
{
	return login + "@miun.se";
}

std::string person::get_login() const
{
	return login;
}

std::string person::get_name() const
{
	return name;
}
