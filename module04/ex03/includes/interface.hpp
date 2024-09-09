#ifndef INTERFACE_HPP
# define INTERFACE_HPP

#include <iostream> // IWYU pragma: keep
#include "colors.hpp" // IWYU pragma: keep

/* -------CLASSES------- */
class ICharacter;
class Character;
class AMateria;
class Cure;
class Fire;
class MateriaSource;
class IMateriaSource;

void debugPrint(std::string name, int type);

#endif