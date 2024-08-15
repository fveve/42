#include "Weapon.hpp"

Weapon :: Weapon(const  string &type)
{
	this->setType(type);
}

Weapon :: ~Weapon()
{

}

 string Weapon :: getType() const
{
	return(type);
}

void Weapon :: setType(const  string &type)
{
	this->type = type;
}
