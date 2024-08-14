#include "Zombie.hpp"
Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{

    std::string name;
    std::string chump_name;

	std::cout << "The name of the zombie :";
    std::cin >> name;

    Zombie *zombie_heap = newZombie(name);
    zombie_heap->announce();
    delete zombie_heap;

	std::cout << "Random chump name: ";
    std::cin >> chump_name;
    randomChump(chump_name);
    return (0);
}