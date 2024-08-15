
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Weapon {
	private :
		 string type;
	public :
		Weapon(const  string &type);
		~Weapon();
		 string getType() const;
		void	setType(const string &type);
};