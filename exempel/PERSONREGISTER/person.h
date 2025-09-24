#ifndef PERSON_H
#define PERSON_H

#include <string>

class person
{
public:
	person(std::string name, std::string login);
	virtual std::string get_email() const = 0;
	virtual std::string get_login() const;
	virtual std::string get_name() const;
	virtual ~person() = default;


private:
	std::string name;
	std::string login;

};

#endif
