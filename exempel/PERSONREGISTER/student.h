#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"

class student : public virtual person
{
public:
	student(std::string name, std::string login);
	std::string get_email() const override;

};


#endif