#ifndef REPLACE_HPP
# define REPLACE_HPP


#include "colors.hpp"
#include <iostream>
#include <string>

typedef std::string str;

int		findAndReplace(const str filename, const str set1, const str set2);
void	error(str errorMsg);

#endif