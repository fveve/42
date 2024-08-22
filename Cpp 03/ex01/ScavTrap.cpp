#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->guarding_gate = false;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ScavTrap): ClapTrap(ScavTrap)
{
	this->guarding_gate = ScavTrap.guarding_gate;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->guarding_gate = false;
	std::cout << "ScavTrap Constructor for the name " << this->Name << " called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor for " << this->Name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->Name = src.Name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else if (this->energyPoints == 0)
		std::cout << "ScavTrap " << this->Name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ScavTrap " << this->Name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->guarding_gate == false)
	{
		this->guarding_gate = true;
		std::cout << "ScavTrap " << this->Name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->Name << " is already guarding the gate." << std::endl;
}