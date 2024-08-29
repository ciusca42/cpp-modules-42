#ifndef REPLACE_HPP
# define REPLACE_HPP


#include "colors.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

typedef std::string str;

class Replace {

	public:
		Replace();
		~Replace();
		int		findAndReplace(const str filename, const str set1, const str set2);
	
	private:
		std::ifstream inFile;
		std::ofstream outFile;
};

#endif