#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombies = new Zombie[N];
	for (int x; x < N; x++)
		zombies[x].set_name(name);
	return (zombies);
}
