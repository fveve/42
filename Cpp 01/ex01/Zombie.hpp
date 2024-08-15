#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

using namespace std;

class	Zombie{
	private :
		 string name;
	public :
		Zombie ();
		~Zombie();
		Zombie* zombieHorde( int N, string name );
		void	set_name( string name)
		{
			this->name = name;
		};
		void	announce(){
			 cout << name << ":  BraiiiiiiinnnzzzZ...\n";
		};
};

Zombie* zombieHorde( int N, string name );

#endif