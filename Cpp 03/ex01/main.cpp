#include "ScavTrap.hpp"

int main()
{
	ScavTrap c;
	ScavTrap d("Scavtrap");
	c.attack("CloneTrap");
	c.beRepaired(22);
	c.takeDamage(21);
	c.beRepaired(22);
	c.guardGate();
	c.guardGate();
	d.attack("ScavTrap_2");
	d.takeDamage(101);
	d.takeDamage(15);
	d.attack("ScavTrap_2");
	return (0);
}