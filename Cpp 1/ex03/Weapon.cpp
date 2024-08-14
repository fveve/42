#include "Weapon.hpp"

Weapon :: Weapon(const std :: string &type)
{
	this->setType(type);
}

Weapon :: ~Weapon()
{

}

std :: string Weapon :: getType() const
{
	return(type);
}

void Weapon :: setType(const std :: string &type)
{
	this->type = type;
}
