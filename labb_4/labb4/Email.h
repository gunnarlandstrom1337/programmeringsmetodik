#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <iostream>

class Email
{
public:
	struct CompSubjectWhoDate {
		bool operator() (const Email& lhs, const Email& rhs) {
			if (lhs.subject == rhs.subject) {
				if (lhs.who == rhs.who) {
					return lhs.date < rhs.date;
				}
				return lhs.who < rhs.who;
			}
			return lhs.subject < rhs.subject;
		}

	};

	struct CompDateWhoSubject {
		bool operator()(const Email& lhs, const Email& rhs) {
			if (lhs.date == rhs.date) {
				if (lhs.who == rhs.who) {
					return lhs.subject < rhs.subject;
				}
				return lhs.who < rhs.who;
			}
			return lhs.date < rhs.date;
		}
	};

	struct CompWhoDateSubject {
		bool operator()(const Email& lhs, const Email& rhs) {
			if (lhs.who == rhs.who) {
				if (lhs.date == rhs.date) {
					return lhs.subject < rhs.subject;
				}
				return lhs.date < rhs.date;
			}
			return lhs.who < rhs.who;
		}
	};

	Email() = delete;
	Email(std::string subject, std::string who, std::string date);
	
	std::string& getSubject() { return subject; }
	std::string& getWho() { return who; }
	std::string& getDate() { return date; }
	

	friend CompSubjectWhoDate;
	friend CompDateWhoSubject;
	friend CompWhoDateSubject;
	friend std::ostream& operator<<(std::ostream& os, const Email& obj);
private:
	std::string subject;
	std::string who;
	std::string date;
};

#endif

