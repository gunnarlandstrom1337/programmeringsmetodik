#ifndef TEACHER_H
#define TEACHER_H
#include "person.h"

class teacher : public person
{

public:
	teacher(std::string name, std::string login);

private:
	std::string name;
	std::string login;



};

#endif
