#pragma once

#include <iostream>

class ClapTrap{

	protected :
		std::string Name;
		int	hitPoints;
		int energyPoints;
		int attackDamage;
	public :
		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap (const ClapTrap&copy);
		ClapTrap &operator=(const ClapTrap &ClapTrap);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};