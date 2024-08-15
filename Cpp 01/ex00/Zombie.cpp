#include "Zombie.hpp"

Zombie :: Zombie( string str){
	name = str;
}

Zombie :: ~Zombie(){

	cout << "Zombie " << name << " has been destroyed." << endl;
}

void Zombie :: 	announce(){	
	 cout << name << ":  BraiiiiiiinnnzzzZ...\n";
};

