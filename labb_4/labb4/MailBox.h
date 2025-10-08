#ifndef MAILBOX_H
#define MAILBOX_H
#include <vector>
#include <algorithm>
#include "Email.h"

class MailBox
{
public:
	MailBox() = default;

	void push(Email obj) {
		emailVec.push_back(obj);
	}

	std::vector<Email>& getMailbox() { return emailVec; }
	void SortWho() { std::sort(emailVec.begin(), emailVec.end(), Email::CompWhoDateSubject()); }
	void SortDate() { std::sort(emailVec.begin(), emailVec.end(), Email::CompDateWhoSubject()); }
	void SortSubject() { std::sort(emailVec.begin(), emailVec.end(), Email::CompSubjectWhoDate()); }

private:
	std::vector<Email> emailVec;

};


#endif
