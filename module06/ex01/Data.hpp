#ifndef DATA_HPP
# define DATA_HPP

#include <iostream> // IWYU pragma: keep

class Data {
	public:
		Data();
		Data(std::string name, int age, bool rept);
		~Data();
		Data(const Data &obj);

		std::string getName() const;
		int getAge() const;
		bool getRept() const;
	private:
		std::string name;
		int			age;
		bool		is_reptilian;
};

#endif