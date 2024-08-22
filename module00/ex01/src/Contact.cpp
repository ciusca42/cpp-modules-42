#include "../includes/phone.hpp"

Contact::Contact() : name(""), last_name(""), nickname(""),
	phone_number(""), secret("") {}

Contact::~Contact() {
}

std::string Contact::get_secret() const {
	return this->secret;
}

std::string Contact::get_name() const {
	return this->name;
}

std::string Contact::get_last() const {
	return this->last_name;
}

std::string Contact::get_nickname() const {
	return this->nickname;
}

std::string Contact::get_number() const {
	return this->phone_number;
}

void Contact::set_name(std::string name) {
	this->name = name;
}

void Contact::set_last(std::string last) {
	this->last_name = last;
}

void Contact::set_secret(std::string secret) {
	this->secret = secret;
}

void Contact::set_number(std::string phone_number) {
	this->phone_number = phone_number;
}

void Contact::set_nickname(std::string nickname) {
	this->nickname = nickname;
}
