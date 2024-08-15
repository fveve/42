#pragma once

#include <iostream>
#include <string>

class Brain
{
	private :
		std::string ideas[100];
	public :
		Brain();
		Brain(const Brain&);
		~Brain();
		Brain &operator=(const Brain&);
		std::string get_idea(unsigned int index);
};