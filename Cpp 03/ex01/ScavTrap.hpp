#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		bool guarding_gate;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &ScavTrap);
		ScavTrap(std::string name);
		virtual ~ScavTrap();
		ScavTrap &operator=(const ScavTrap &src);
		void attack(const std::string &target);
		void guardGate(void);
};