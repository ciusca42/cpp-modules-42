
#include "../includes/Replace.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cstdio>

void error(std::string error) {
	std::cerr << ROSE300 "Error: ";
	std::cerr << STONE300 << error << '\n' << RESET;
}

int	parseInput(const str filename, const str set1, const str set2) {
	
	if (filename.empty() || set1.empty() || set2.empty()) {
    	error("Arguments cannot be empty");
    	return 0;
	}
	else if (set1 == set2) {
		error ("Why do you even need a replacment?!");
		return 0;
	}
	return 1;
}

int	Replace::findAndReplace(const str filename, const str set1, const str set2) {
	str				line;
	int				start;
	str				newFileName;

	if (!parseInput(filename, set1, set2))
		return 0;

	inFile.open(filename.c_str());
	if (!inFile.is_open()) {
		error("'" + filename + "' does not exist");
		return 0;
	}

	start = filename.find_last_of(".");
	int temp = filename.length() - start;
	newFileName = filename;
	newFileName.resize(filename.length() - temp);

	outFile.open((newFileName + ".replace").c_str() , std::ios::trunc);
	if (!outFile.is_open()) {
		error("something went wrong: cannot create the replacment file");
		return 0;
	}

	while (getline(inFile, line, '\0')) {
		start = line.find(set1);
		while (start != -1) {
			line.erase(start, set1.length());
			line.insert(start, set2);
			start = line.find(set1);
		}
		outFile << line;
	}
	inFile.close();
	outFile.close();
	return (1);
}

Replace::Replace( void ) {}

Replace::~Replace ( void ) {}