
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Weapon {
	private :
		std :: string type;
	public :
		Weapon(const std :: string &type);
		~Weapon();
		std :: string getType() const;
		void	setType(const std ::string &type);
};