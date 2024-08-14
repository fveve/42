#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

using namespace std;

class	Zombie{
	private :
		std :: string name;
	public :
		Zombie ();
		~Zombie();
		Zombie* zombieHorde( int N, std::string name );
		void	set_name(std :: string name)
		{
			this->name = name;
		};
		void	announce(){
			std :: cout << name << ":  BraiiiiiiinnnzzzZ...\n";
		};
};

Zombie* zombieHorde( int N, std::string name );

#endif