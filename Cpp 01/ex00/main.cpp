#include "Zombie.hpp"
Zombie* newZombie( string name );
void randomChump( string name );

int main(void)
{

    string name;
    string chump_name;

	cout << "The name of the zombie :";
    cin >> name;

    Zombie *zombie_heap = newZombie(name);
    zombie_heap->announce();
    delete zombie_heap;

	cout << "Random chump name: ";
    cin >> chump_name;
    randomChump(chump_name);
    return (0);
}