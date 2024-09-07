#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class WrongAnimal {
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal & obj);
		WrongAnimal & operator=(const WrongAnimal & obj);
};

#endif