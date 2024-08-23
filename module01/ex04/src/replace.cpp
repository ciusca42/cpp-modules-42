
#include "../includes/replace.hpp"
#include <fstream>
#include <string>
#include <sstream>

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

int	findAndReplace(const str filename, const str set1, const str set2) {
	std::ifstream	inFile;
	std::ofstream	outFile;
	str				line;
	int				start;

	if (!parseInput(filename, set1, set2))
		return 0;

	inFile.open(filename.c_str());
	if (!inFile.is_open()) {
		error("'" + filename + "' does not exist");
		return 0;
	}
	outFile.open((filename + ".replace").c_str() , std::ios::trunc);
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
	return (1);
}