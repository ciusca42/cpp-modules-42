#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "../includes/phone.hpp"

class Contact {
	public:
		Contact();
		~Contact();
	private:
		std::string name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string email;
};

#endif