#ifndef LAB_ASSISTANT_H
#define LAB_ASSISTANT_H
#include <string>
#include "teacher.h"
#include "student.h"

// MULTIPLE LEGACY / inherit
// VIRTUALL LEGACY / inherit

class lab_assistant : public teacher, public student
{
public:
	lab_assistant(const std::string& name, const std::string& login);
	std::string get_email()const override;

private:



};


#endif 

