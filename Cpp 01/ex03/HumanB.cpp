#include "HumanB.hpp"

HumanB :: HumanB( string name)
{
	this->name = name;
}

HumanB :: ~HumanB()
{
	 cout << name << " is dead" <<  endl;
}

void	HumanB :: attack()
{
	 cout << name << " attacks with their " << weapon->getType() <<  endl;
}

void	HumanB :: setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}