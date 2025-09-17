#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"

class student : public person
{
public:
	student(std::string name, std::string login);
	std::string get_email() const;
	std::string get_login() const;
	std::string get_name() const;

private:
	std::string name;
	std::string login;


};


#endif