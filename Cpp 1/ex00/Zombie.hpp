#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

using namespace std;

class	Zombie{
	private :
		std :: string name;
	public :
		Zombie (std :: string string);
		~Zombie();
		Zombie* newZombie( std::string name );
		void randomChump( std::string name );
		void	announce();
};

#endif