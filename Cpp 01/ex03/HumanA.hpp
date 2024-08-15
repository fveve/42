#include "Weapon.hpp"
#pragma once

class HumanA {
	private :
		 string name;
		Weapon	&_weapon;
	public :
		HumanA( string name, Weapon &weapon);
		~HumanA();
		void attack();
};