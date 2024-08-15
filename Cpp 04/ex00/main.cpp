#include "Animal.hpp"
#include "WrongAnimal.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound(); //will output the cat sound!
	meta2->makeSound();
	delete i2;
	delete meta2;
	return 0;
}