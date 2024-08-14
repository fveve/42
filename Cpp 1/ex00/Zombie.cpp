#include "Zombie.hpp"

Zombie :: Zombie(std :: string str){
	name = str;
}

Zombie :: ~Zombie(){

	std::cout << "Zombie " << name << " has been destroyed." << std::endl;
}

void Zombie :: 	announce(){	
	std :: cout << name << ":  BraiiiiiiinnnzzzZ...\n";
};

