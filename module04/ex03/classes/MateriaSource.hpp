#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &obj);
		MateriaSource & operator=(const MateriaSource &obj);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria	*_known[4];
		int			_nbKnown;
};

#endif