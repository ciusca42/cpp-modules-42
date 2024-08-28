#include "../includes/phone.hpp"

PhoneBook::PhoneBook() : last(0), amount(0) {}

PhoneBook::~PhoneBook() {
}

int check_input( std::string line ) {
	if (line == "") {
		system("clear");
		std::cerr << ROSE300 "\tInput cannot be empty\n" RESET;
		return 0;
	}
}

void PhoneBook::add() {

	std::string new_name;
	std::string last;
	std::string new_secret;
	std::string new_nick;
	std::string new_number;

	if (this->last == 8) {
		this->last = 0;
	}
	system("clear");
	std::cout << "    " LIME400 "ADD " RESET "operation: " LIME200 "please follow the steps:\n\n" RESET;

	while (1) {
		std::cout << "    Insert the contact " EMERALD300 "NAME" RESET ": ";
		getline(std::cin, new_name);
		
		std::cout << RESET "    Insert the contact " EMERALD300 "LAST NAME" RESET ": " ;
		if (getline(std::cin, last).eof());
			close_phonebook();
		if (new_name == "" || last == "" || new_nick == "" || new_number == "" || new_secret == "") {
			std::cerr << ROSE300 "\tInput cannot be empty\n" RESET;
			continue;
		}
		std::cout << RESET "    Insert the contact " EMERALD300 "NICKNAME" RESET ": " ;
		getline(std::cin, new_nick);
		if (new_name == "" || last == "" || new_nick == "" || new_number == "" || new_secret == "") {
			std::cerr << ROSE300 "\tInput cannot be empty\n" RESET;
			continue;
		}
		std::cout << RESET "    Insert the contact " EMERALD300 "NUMBER" RESET ": " ;
		getline(std::cin, new_number);
		if (new_name == "" || last == "" || new_nick == "" || new_number == "" || new_secret == "") {
			system("clear");
			std::cerr << ROSE300 "\tInput cannot be empty\n" RESET;
			continue;
		}
		std::cout << RESET "    Insert the contact " EMERALD300 "SECRET" RESET ": " ;
		getline(std::cin, new_secret);
		if (new_name == "" || last == "" || new_nick == "" || new_number == "" || new_secret == "") {
			std::cerr << ROSE300 "\tInput cannot be empty\n" RESET;
			continue;
		}
	}
	
	

	contacts[this->last].set_name(new_name);
	contacts[this->last].set_last(last);
	contacts[this->last].set_number(new_number);
	contacts[this->last].set_secret(new_secret);
	contacts[this->last].set_nickname(new_nick);
	if (this->amount < 8)
		this->amount++;
	this->last++;
	system("clear");
	std::cout <<  BG_LIME400  "Contact has been added correctly! \n" RESET;
}


void format_string(std::string str, int align) {
	if (str.length() > 10) {
		str.resize(9);
		str.append(".");
	}
	std::cout << VIOLET300 <<  std::setw(align) << str << RESET;
	std::cout << "|";
}

void ContactInfo(Contact &contact) {
	std::cout << "-------------------------------------------------\n";
	std::cout << "| " EMERALD300 "    Name: " RESET;
	std::cout << contact.get_name() << "\n";
	std::cout << "| " EMERALD300 "    Last: " RESET;
	std::cout << contact.get_last() << "\n";
	std::cout << "| " EMERALD300 "    Nick: " RESET;
	std::cout << contact.get_nickname() << "\n";
	std::cout << "| " EMERALD300 "    Phone: " RESET;
	std::cout << contact.get_number() << "\n";
	std::cout << "| " EMERALD300 "    Secret: " RESET;
	std::cout << contact.get_secret() << "\n";
	std::cout << "-------------------------------------------------\n";
}

void PhoneBook::search() {

	std::ostringstream	temp;
	std::string 		input;
	int					index;

	system("clear");
		// std::cout << std::setw(10) << "|\n";
	if (!this->amount) {
		std::cout << ROSE300 "No contacts available: use '" LIME200 "ADD" ROSE300 "' option to create one\n" RESET;
		return ;
	}
	while (1) {
		std::cout << "-------------------------------------------------\n";
		std::cout << "| " EMERALD300 "    Index |" RESET " " EMERALD300 "     Name" RESET " | " EMERALD300 "     Last " RESET "| " EMERALD300 " Nickname " RESET "|\n";
		std::cout << "-------------------------------------------------\n";
		for (int i = 0; i < this->amount; i++) {
			temp << i + 1;
			std::cout << "|";
			format_string(temp.str(), 11);
			format_string(contacts[i].get_name(), 11);
			format_string(contacts[i].get_last(), 11);
			format_string(contacts[i].get_nickname(), 11);
			std::cout << "\n";
			std::cout << "-------------------------------------------------\n";
			temp.str("");	
		}
		std::cout << STONE400 "Select the index of the contact: " RESET;
		getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << ROSE300 "\nsee ya...\n" RESET;
			_Exit(0);
		}
		index = atoi(input.c_str());
		if (!index) {
			system("clear");
			std::cout << ROSE300 "\nInvalid index: please select a valid one\n\n" RESET;
			continue;
		}
		if (index < 0 || index > this->amount) {
			system("clear");
			std::cout << ROSE300 "\nInvalid index: please select a valid one\n\n" RESET;
			continue;
		}
		ContactInfo(contacts[index - 1]);
		std::cout << STONE300 "Do you want to search for another contact? [y/n]: " RESET;
		getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << ROSE300 "\nsee ya...\n" RESET;
			_Exit(0);
		}
		if (input == "n" || input == "N") {
			system("clear");
			break;
		}
		system("clear");
	}
}
