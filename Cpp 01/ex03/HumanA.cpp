#include "HumanA.hpp"

HumanA :: HumanA( string name, Weapon &weapon):_weapon(weapon)
{
	this->name = name;
}

HumanA :: ~HumanA()
{
	 cout << name << " is dead" <<  endl;
}

void	HumanA :: attack()
{
	 cout << name << " attacks with their " << this->_weapon.getType() <<  endl;
}
