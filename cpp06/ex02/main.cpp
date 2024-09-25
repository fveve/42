/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:53:10 by arafa             #+#    #+#             */
/*   Updated: 2024/09/25 15:18:54 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <random>

Base *generate(void)
{
	Base *ref;
	srand(time(0));
	int random_number = rand() % 3 + 1;
	if (random_number == 1)
	{
		ref = new A;
	}
	else if (random_number == 2)
	{
		ref = new B;
		
	}
	else
	{
		ref = new C;
		
	}
	return (ref);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
    {
        std::cout << "This is class A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "This is class B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "This is class C" << std::endl;
    }
}

void identify(Base& p)
{
	Base &global= p;
	try 
    {
		A &ref_A = (dynamic_cast<A&>(p));
        std::cout << "This is class A" << std::endl;
		global = ref_A;
    }
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try 
    {
		B &ref_B = (dynamic_cast<B&>(p));
        std::cout << "This is class B" << std::endl;
		global = ref_B;
    }
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try 
    {
		C &ref_C = (dynamic_cast<C&>(p));
        std::cout << "This is class c" << std::endl;
		global = ref_C;
    }
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	srand(time(NULL)); // enables the randomness of the generate function
	for (int j = 0; j < 5; j++)
	{
		Base *Test = generate();
		if (Test == NULL)
			return (1);
		else
		{
			identify(Test);
			identify(*Test);
			delete (Test);

			std::cout << std::endl;
		}
	}
	return (0);
}