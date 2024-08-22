#include "ClapTrap.hpp"

int main()
{
		ClapTrap a;
		ClapTrap b("bob");
		std::cout << std::endl;
		a.attack("some other robot");
		std::cout << std::endl;
		a.takeDamage(10);
		a.takeDamage(10);
		std::cout << std::endl;
		a.beRepaired(5);
		std::cout << std::endl;
		a.attack("some other other robot");
		std::cout << std::endl;
		b.beRepaired(3);
		std::cout << std::endl;
		for (int i = 0; i < 12; i++)
			b.attack("rob");
		std::cout << std::endl;
		b.beRepaired(3);
	return (0);
}