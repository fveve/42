#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name)
{
	this->Name = Name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 10;
	
	std::cout << "ClapTrap " << this->Name << " is initialized." << std::endl;

}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap::ClapTrap()
{
	this->Name = "Random bum";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 10;
	
	std::cout << "ClapTrap " << this->Name << " is initialized." << std::endl;

}

ClapTrap :: ~ClapTrap()
{
	std::cout << "ClapTrap " << this->Name << " is destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->Name = src.Name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->Name << " attacks " << this->hitPoints <<   " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else if (this->hitPoints > 0)
		std::cout << "ClapTrap " << this->Name << "does not have enough energy to attack the target " << target << std::endl;
	else
		std::cout << "ClapTrap " << this->Name << " is dead so he can't attack " << target << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->Name << " takes " << amount << " damages." << std::endl;
	this->hitPoints -= 	amount;
	if (this->hitPoints <= 0)
		std::cout << this->Name << " has no more hit points , therefore is dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->Name << " healed " << amount <<   " points." << std::endl;
		this->hitPoints+= amount;
		this->energyPoints--;
	}
	else  if (this->hitPoints > 0)
		std::cout << "ClapTrap " << this->Name << " has no energy therefore can longer heal himself." << std::endl;
	else
		std::cout << "ClapTrap " << this->Name << "is dead therefore can longer heal himself." << std::endl;
}