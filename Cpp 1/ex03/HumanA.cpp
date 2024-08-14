#include "HumanA.hpp"

HumanA :: HumanA(std :: string name, Weapon &weapon):_weapon(weapon)
{
	this->name = name;
}

HumanA :: ~HumanA()
{
	std :: cout << name << " is dead" << std :: endl;
}

void	HumanA :: attack()
{
	std :: cout << name << " attacks with their " << this->_weapon.getType() << std :: endl;
}
