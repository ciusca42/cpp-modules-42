#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "../includes/phone.hpp"

class Contact {
	public:
		Contact();
		~Contact();
		std::string get_name() const;
		std::string get_last() const;
		std::string get_nickname() const;
		std::string get_number() const;
		std::string get_secret() const;
		void set_name(std::string name);
		void set_last(std::string last);
		void set_nickname(std::string nickname);
		void set_number(std::string phone_number);
		void set_secret(std::string secret);
	private:
		std::string name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string secret;
};

#endif