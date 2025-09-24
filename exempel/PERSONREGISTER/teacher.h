#ifndef TEACHER_H
#define TEACHER_H
#include "person.h"

class teacher : public virtual person
{
public:
	teacher(std::string name, std::string login);
	std::string get_email() const override;

};

#endif
