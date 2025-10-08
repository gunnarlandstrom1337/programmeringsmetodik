#include "Email.h"



Email::Email(std::string who, std::string date, std::string subject) : subject(subject), who(who), date(date)
{

}

std::ostream& operator<<(std::ostream& os, const Email& obj)
{
	std::cout << "Who: " << obj.who << "\nDate: " << obj.date << "\nSubject: " << obj.subject << "\n\n";
	return os;
}
