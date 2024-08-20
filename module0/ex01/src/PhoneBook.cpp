#include "../includes/phone.hpp"

PhoneBook::PhoneBook() : last(0), amount(0) {}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add() {

	std::string new_name;
	std::string last;
	std::string new_email;
	std::string new_nick;
	std::string new_number;

	std::cout << "    " LIME400 "ADD " RESET "operation: " LIME200 "please follow the following steps:\n" RESET;

	std::cout << "    Insert the " VIOLET300 "contact name" RESET ": ";
	getline(std::cin, new_name);
	std::cout << RESET "    Insert the contact " VIOLET300 "last_name" RESET ": " ;
	getline(std::cin, last);
	std::cout << RESET "    Insert the contact " VIOLET300 "nickname" RESET ": " ;
	getline(std::cin, new_nick);
	std::cout << RESET "    Insert the contact " VIOLET300 "email" RESET ": " ;
	getline(std::cin, new_email);
	std::cout << RESET "    Insert the contact " VIOLET300 "number" RESET ": " ;
	getline(std::cin, new_number);
	if (std::cin.eof()) {
		std::cout << "see ya...\n";
		_Exit(0);
	}

	contacts[this->last].set_name(new_name);
	contacts[this->last].set_last(last);
	contacts[this->last].set_number(new_number);
	contacts[this->last].set_email(new_email);
	contacts[this->last].set_nickname(new_nick);
	amount++;
	this->last++;
	std::cout << INDIGO300 "Contact has been added correctly! \n" RESET;
}

void PhoneBook::search() {
	std::cout << "Searching for a contact\n";
}

void PhoneBook::show() {
	for (int i = 0; i < amount; i++) {
		std::cout << i + 1 << ". name = " << this->contacts[i].get_name() << '\n';
		std::cout << i + 1 << ". last_name = " << this->contacts[i].get_last() << '\n';
		std::cout << i + 1 << ". nickname = " << this->contacts[i].get_nickname() << '\n';
		std::cout << i + 1 << ". email = " << this->contacts[i].get_email() << '\n';
		std::cout << i + 1 << ". phone number = " << this->contacts[i].get_number() << '\n';
	}
}
