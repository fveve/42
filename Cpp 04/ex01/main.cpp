#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
	Animal *j[10];

	for (int x = 0; x < 5 ; x++)
	{
		j[x] = new Dog();
		j[9 - x] = new Cat();
	}
	for (int x = 0; x < 10 ; x++)
	{
		delete j[x];
	}
	return 0;
}
