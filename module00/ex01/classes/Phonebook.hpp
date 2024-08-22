#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "../includes/phone.hpp"

class PhoneBook{
	
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
	private:
		int		last;
		int		amount;
		Contact contacts[8];
};

#endif