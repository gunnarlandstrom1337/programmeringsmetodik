#ifndef PERSON_H
#define PERSON_H

#include <string>

class person
{
public:
	person(std::string name, std::string login);
	virtual std::string get_email() const;
	virtual std::string get_login() const;
	virtual std::string get_name() const;


private:
	std::string name;
	std::string login;

};

#endif
