#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

class WrongCat {
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat & obj);
		WrongCat & operator=(const WrongCat & obj);
};

#endif